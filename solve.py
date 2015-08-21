#!/usr/bin/env python

import os
import os.path
import sys
import string

if len(sys.argv) == 1:
	print "Usage:", sys.argv[0], "Problem Title"
	exit(-1)

newdir = "./Algorithms/"
fname = ""
suffix = ".cc"

template = '''/*
copyright xu(xusiwei1236@163.com), all right reserved.

{0}
{1}


*/

int main(int argc, char* argv[])
{{
	return 0;
}}
'''

title = ""
for i in range(1, len(sys.argv)):
	if i != len(sys.argv)-1:
		title = title + sys.argv[i] + " "
	else:
		title = title + sys.argv[i]
	
content = template.format(title, "=" * (1+len(title)))
#print "prepare content:\n", content

for i in range(1, len(sys.argv)):
	w = sys.argv[i]
	newdir = newdir + string.capitalize(w[0]) + w[1:]
	first = string.lower(w[0]) if i == 1 else string.capitalize(w[0])
	fname = fname + first + w[1:]

fname = newdir + "/" + fname + suffix

# exists ?
if os.path.exists(newdir):
	print "dir:", newdir, "exists!"
	exit(-2)

# crate dir
print "create dir:", newdir
os.mkdir(newdir)

# crate file
print "create file:", fname
fo = file(fname, 'w')
if fo == None:
	print "touch file:", fname, "failed!"
	exit(-3)

fo.write(content)



