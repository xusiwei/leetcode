/*
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
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isAnagram(const char* s, const char* t) {
    char cs[256] = {0}, ct[256] = {0};
    while (*s) cs[*s++]++;
    while (*t) ct[*t++]++;
    return !memcmp(cs, ct, sizeof(cs));
}

int main(int argc, char* argv[])
{
	const char* s = "anagram";
	const char* t = "nagaram";

	if (argc > 2) {
		s = argv[1];
		t = argv[2];
	}
    printf("isAnagram(%s, %s): %s\n", s, t, isAnagram(s, t) ? "true" : "false");
    return 0;
}
