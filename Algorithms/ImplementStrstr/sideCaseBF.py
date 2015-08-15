#!/usr/bin/python
# USAGE: echo 100 | gen.py | ./a.out
# complixty of BF-search is: O((m-n)*n)
# it means that `text` likes `AAA..A`, pat likes `AA..B`
# and, when n == m/2, the time goes max.

M = eval(raw_input())
N = M/2

print 'A' * (M-1) + 'B'
print 'A' * (N-1) + 'B'
