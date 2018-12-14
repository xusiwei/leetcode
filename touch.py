#!/usr/bin/env python
import os
import sys

template = '''/*
copyright xu(xusiwei1236@163.com), all right reserved.

{0}
{1}

// PLACE PROBLEM DESCRIPTIONS HERE
*/

// PLACE PROBLEM SOLUTIONS HERE

int main(int argc, char* argv[])
{{
    return 0;
}}
'''

def main(argv):
	if len(argv) <= 1:
		print('Usage: {} URL\n\tURL -- problem URL'.format(argv[0]))
		exit(1)
	url = argv[1]
	_, title = os.path.split(url.strip('/'))
	words = map(str.capitalize, title.split('-'))
	print('title: {}, words: {}'.format(title, str(words)))

	directory = os.path.join('Algorithms', ''.join(words))
	if os.path.exists(directory):
		print(directory, 'Already exists, exit!')
		exit(1)
	print('create solution dir : ' + directory)
	os.makedirs(directory)

	dwords = words[:]; dwords[0] = dwords[0].lower()
	solution = os.path.join(directory, ''.join(dwords) + '.cc')
	with open(solution, 'w') as f:
		print('create solution file: ' + solution)
		title = ' '.join(words)
		f.write(template.format(title, '='*len(title)))
	print('Done')

if __name__ == '__main__':
	main(sys.argv)
