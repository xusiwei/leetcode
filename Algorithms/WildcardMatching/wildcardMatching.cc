/*
copyright xu(xusiwei1236@163.com), all right reserved.

Wildcard Matching
==================

Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") ¡ú false
isMatch("aa","aa") ¡ú true
isMatch("aaa","aa") ¡ú false
isMatch("aa", "*") ¡ú true
isMatch("aa", "a*") ¡ú true
isMatch("ab", "?*") ¡ú true
isMatch("aab", "c*a*b") ¡ú false
*/

#include <stdio.h>
#include <assert.h>

#ifdef DEBUG
#define trace printf
#else // DEBUG
#define trace
#endif // DEBUG

#ifdef RECUSIVE
// TLE(Time Limit Exceeded)
bool isMatch(const char* s, const char* p) {
    assert(s && p);
    trace("match %s, %s\n", s, p);
    if(*s == '\0' && *p == '\0') return true;
    
    if(*p == '*') {
        while(*p == '*') p++; // skip duplicate * on pattern.
        do {
            if(isMatch(s, p+1)) return true;
        }while(*s++);
    }
    
    return (*p == '?' || *p == *s) && isMatch(s+1, p+1);
}
#else
bool isMatch(const char* s, const char* p) {
    const char* star = NULL, *ss = s;
    while(*s) {
        trace("match %s, %s\n", s, p);
        if(*p == '?' || *p == *s) {
            s++;
            p++;
            continue;
        }
        if(*p == '*') {
            star = p++;
            ss = s;
            continue;
        }
        if(star) {
            p = star+1;
            s = ++ss;
            continue;
        }
        return false;
    }
    
    while(*p == '*') p++;
    return !*p;
}
#endif

int main(int argc, char* argv[])
{
// "aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba", "a*******b"
    char s[256] = "aabbb";
    char p[256] = "?*";
    
    do {
        printf("isMatch(%s, %s) -> %s\n", s, p, isMatch(s, p) ? "true" : "false");
    }while(scanf("%s%s", s, p) == 2);
    return 0;
}
