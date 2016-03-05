#!/usr/bin/env python

import re
import os
import os.path
import sys
import string
import urllib
from HTMLParser import HTMLParser
from operator import __mod__

class QuestionParser(HTMLParser):
	DEBUG = False

	def __init__(self):
		HTMLParser.__init__(self)
		self.start_title_flag = None
		self.start_content_flag = None
		self.question_title = ''
		self.question_content = ''

	def handle_starttag(self, tag, attrs):
		if self.DEBUG:
			print 'start TAG:', tag, ', ATTRS:', attrs
		if tag == 'div' and ('class', 'question-title') in attrs:
			self.start_title_flag = True
		elif tag == 'div' and ('class', 'question-content') in attrs:
			self.start_content_flag = True

	def handle_endtag(self, tag):
		if self.DEBUG:
			print 'end TAG:', tag
		if self.start_title_flag and tag == 'div':
			self.start_title_flag = False
		elif self.start_content_flag and tag == 'div':
			self.start_content_flag = False

	def handle_data(self, data):
		if self.DEBUG:
			print 'DATA:', data
		if self.start_title_flag:
			self.question_title += data
		elif self.start_content_flag:
			self.question_content += data

	def get_question_title(self):
		t = self.question_title
		return t[t.find('. ')+1: t.find('My Submissions')].strip()

	def get_question_content(self):
		c = self.question_content.replace('\r', '')
		return c[:c.find('Subscribe to see which companies asked this question')].strip()

basedir = "Algorithms/"
filename = ""
suffix = ".cc"

template = '''/*
copyright xu(xusiwei1236@163.com), all right reserved.

{0}
{1}

{2}
*/

int main(int argc, char* argv[])
{{
    return 0;
}}
'''


if __name__ == '__main__':
	if len(sys.argv) == 1:
		print "Usage:", sys.argv[0], "Problem-URL"
		exit(-1)

	# fetch question page
	URL = sys.argv[1]
	page = urllib.urlopen(URL).read()

	# parsing question
	parser = QuestionParser()
	parser.feed(page)

	# format by template
	title = parser.get_question_title()
	split = '=' * (len(title)+1)
	content = template.format(title, split, parser.get_question_content())
	print 'content ready:\n', content

	# prepare filename
	twords = title.split(' ')
	for i in range(0, len(twords)):
		w = twords[i].replace("'", "")
		basedir = basedir + string.capitalize(w[0]) + w[1:]
		first = string.lower(w[0]) if i == 0 else string.capitalize(w[0])
		filename = filename + first + w[1:]
	filename = basedir + "/" + filename + suffix

	# check directory exists ?
	if os.path.exists(basedir):
		print "dir:", basedir, "exists!"
		exit(-2)
	print "create dir:", basedir
	os.mkdir(basedir)

	# write to file
	print "create file:", filename
	fo = file(filename, 'w')
	if fo == None:
		print "touch file:", filename, "failed!"
		exit(-3)
	fo.write(content)

	# update README.md
	f = file('README.md', 'r')
	lines = f.readlines()
	for i in range(len(lines)):
		L = lines[i]
		title_wrap = '| ' + title + '  |'
		if L.find(title) != -1:
			print 'found problem line in README.md:', L
			L = L.replace(title_wrap,  '| [%s](%s)  |' % (title, URL))
			L = L.replace('|  |', '| [C++](%s) |' % filename)
			lines[i] = L
			print 'replaced with:', L
			break
	f.close()
	f = file('README.md', 'w')
	f.writelines(lines)
	f.close()
