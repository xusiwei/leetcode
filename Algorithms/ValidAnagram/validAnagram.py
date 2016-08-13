#!/usr/bin/env python
'''
copyright xu(xusiwei1236@163.com), all right reserved.

Valid Anagram
==============

Given two strings s and t, write a function to determine if t is an anagram of s. 

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.


Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
'''
import sys

class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        cs = [0] * 256
        ct = [0] * 256
        for c in s: cs[ord(c)] += 1
        for c in t: ct[ord(c)] += 1
        return cs == ct

if __name__ == '__main__':
    s = 'anagram'
    t = 'nagaram'

    if len(sys.argv) > 1: s = sys.argv[1]
    if len(sys.argv) > 2: t = sys.argv[2]

    print s, t
    print Solution().isAnagram(s, t)
