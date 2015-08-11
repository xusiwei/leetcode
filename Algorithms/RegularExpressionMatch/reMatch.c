/*
copyright xu(xusiwei1236@163.com), all right reserved.

Regular Expression Matching
============================

Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
*/

/*
do it by hand:
mat(aa\0, a*\0)
0:    mat(aa\0, \0)    false

1:  aa\0, a*\0
    ^     ^
    mat(a\0, \0)    false

2:    aa\0, a*\0
     ^    ^
    mat(\0, \0)        true
*/

#include <stdio.h>
#include <stdbool.h>

#ifdef DEBUG
    #define debug printf
#else // DEBUG
    #define debug
#endif // DEBUG

bool isMatch(char* s, char* p) {
    debug("isMatch %s(%p), %s(%p)\n", s, s, p, p);
    if(s == NULL || p == NULL) return false;
    if(*p == '\0') return *s == '\0'; // for 0, 0;  N, 0.
    
    if(p[1] == '*') {
        int i;
        if(isMatch(s, p+2)) return true; // match zero element
        for(i = 0; s[i] && p[0]; i++) {  // match more
            debug("isMatch %d: %c, %c,  %s(%p)\n", i, s[i], p[0], s, s);
            if(s[i] == p[0] || p[0] == '.') {
                if(isMatch(s+i+1, p+2)) return true;
            }
            else return false;
        }
    }
    else if(*s == *p || *s != '\0' && *p == '.') { // go ahead.
        return isMatch(s+1, p+1);
    }
    return false;
}

bool test(char* s, char* p) {
    printf("isMatch(%s, %s) -> %s\n", s, p, isMatch(s, p) ? "true" : "false");
}

#define isMatch test

int main(int argc, char* argv[])
{
    int i;
#if CASE
isMatch("aa","a");
isMatch("aa","aa");
isMatch("aaa","aa");
isMatch("aa", "a*");
isMatch("aa", ".*");
isMatch("ab", ".*");
isMatch("aab", "c*a*b");

isMatch("aaa", "a*a");

isMatch("aaaaaaaaabbbbbbbbbbbbbbbbbbb", "a*b*");
isMatch("aaaaaaaaaaaaaaaaaaaaa", "a*a*a*aa");

isMatch("", "..*");
#endif

    for(i = 1; i < argc; i += 2) {
        isMatch(argv[i], argv[i+1]);
    }
    return 0;
}

