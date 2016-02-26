/*
copyright xu(xusiwei1236@163.com), all right reserved.

Reverse Words in a String
==========================

Given an input string, reverse the string word by word.



For example,
Given s = "the sky is blue",
return "blue is sky the".



Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space.


click to show clarification.

Clarification:



What constitutes a word?
A sequence of non-space characters constitutes a word.
Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading or trailing spaces.
How about multiple spaces between two words?
Reduce them to a single space in the reversed string.
*/
#include <stdio.h>
#include <string.h>

// reverse range [b, e)
void reverse(char *b, char *e) {
    for (--e; e - b > 0; b++, e--) {
        char t = *b;
        *b = *e;
        *e = t;
    }
}

void reverseWords(char *s) {
    char *p = s, *ws = NULL, *last = s;

    while (*p && *p == ' ') p++; // skip leading space
    ws = p;

    for ( ; *p; p++) {
        while (*p && *p != ' ') p++; // find word end

        reverse(ws, p);
        strncpy(last, ws, p-ws);
        last += (p-ws);

        while (*p && *p == ' ') p++; // for next word
        ws = p;

        if (*p == '\0') break;
        *last++ = ' ';
    }
    reverse(s, last);
    *last = '\0';
}

int main(int argc, char* argv[])
{
    char *s;

    s = strdup("abc s sd f");
    puts(s);
    reverse(s, s + strlen(s));
    puts(s);

#define TEST(str) do {   \
    s = strdup(str);      \
    printf("\"%s\"\n", s); \
    reverseWords(s);       \
    printf("\"%s\"\n", s); \
    } while (0)
    
    TEST("  the   blue  sky  is blue    ");
    TEST("  ");
    return 0;
}

