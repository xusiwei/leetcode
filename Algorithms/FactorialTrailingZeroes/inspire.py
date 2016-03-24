#!/usr/bin/env python

import sys

def fac(n):
	if n <= 1: return 1
	return n * fac(n-1)

def tzs(n):
	s = str(fac(n))
	z = len(s) - 1
	while s[z] == '0':
		z -= 1
	return len(s) - z - 1

def main():
	n = int(sys.argv[1])
	for i in range(1, n+1):
		print i, "\t", tzs(i)

if __name__ == '__main__':
	main()
