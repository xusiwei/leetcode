/*
copyright xu(xusiwei1236@163.com), all right reserved.

Valid Palindrome
=================

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.



For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.



Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

bool isPalindrome(char* s) {
    int i, j;
    
    for (i = 0, j = strlen(s); i < j; i++, j--) {
        while (!isalnum(s[i]) && i < j) i++;
        while (!isalnum(s[j]) && i < j) j--;
        if (i >= j) break;
        
        if (toupper(s[i]) != toupper(s[j])) {
            return false;
        }
    }
    return true;
}

int main(int argc, char* argv[])
{
    char* s = "A man, a plan, a canal: Panama";

    if (argc > 1) {
        s = argv[1];
    }
    
    printf("%d\n", isPalindrome(s));
    return 0;
}

#if 0
char* randrome(int len) {
    int i, j;
    char* s = (char*)malloc((len+1) * sizeof(char));

    for (i = 0; i < len; i++) {
        char c = 0;
        while (!isalnum(c)) {
            c = rand() % (CHAR_MAX);
        }
        s[i] = c;
    }
    for (j = len-1; j >= 0; i++, j--) {
        s[i] = s[j];
    }
    s[i] = '\0';
    return s;
}
#endif
