#!/usr/bin/env python
import re
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

ROMAN_PATTEN = '^M{0,4}(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})$'
COMMON_WORDS = set(['and', 'for', 'to', 'of', 'is'])

def main(argv):
	if len(argv) <= 1:
		print('Usage: {} URL [category]\n\tURL -- problem URL' \
				+ '\n\tcategory -- Algorithms by default'.format(argv[0]))
		exit(1)
	url = argv[1]
	category = argv[2] if len(argv) > 2 else 'Algorithms'

	_, last = os.path.split(url.strip('/'))
	words = last.split('-')
	# print('split words: {}'.format(str(words)))

	title_words = lambda s: re.sub('[a-zA-Z]+', lambda m: str.capitalize(m.group()), s)
	words = map(title_words, words)
	# print('capitalize words: {}'.format(str(words)))

	upper_roman = lambda s: re.match(ROMAN_PATTEN, s.upper()) and s.upper() or s
	words = map(upper_roman, words)
	print('finally words: {}'.format(str(words)))

	directory = os.path.join(category, ''.join(words))
	if os.path.exists(directory):
		print(directory, 'Already exists, exit!')
		exit(1)
	print('create solution dir : ' + directory)
	os.makedirs(directory)

	copies = words[:]
	copies[0] = re.sub('^[a-zA-Z]+', lambda m: str.lower(m.group()), copies[0])
	solution = os.path.join(directory, ''.join(copies) + '.cc')
	with open(solution, 'w') as f:
		print('create solution file: ' + solution)
		words = map(lambda w: (w in COMMON_WORDS) and w.lower() or w, words)
		title = ' '.join(words)
		f.write(template.format(title, '='*len(title)))
	print('Done')

if __name__ == '__main__':
	main(sys.argv)
