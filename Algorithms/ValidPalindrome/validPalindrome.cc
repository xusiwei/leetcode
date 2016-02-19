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
#include <limits.h>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        for (int i = 0, j = s.length() - 1; ; i++, j--) {
            // skip non-alphanumeric characters
            while (!isalnum(s[i]) && i < j) i++;
            while (!isalnum(s[j]) && i < j) j--;
            if (i >= j) break;
            
            //printf("%d: %c, %d:%c\n", i, s[i], j, s[j]);
            if (toupper(s[i]) != toupper(s[j])) {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char* argv[])
{
    string s = "A man, a plan, a canal: Panama";

    if (argc > 1) {
        s = argv[1];
    }
    
    cout << Solution().isPalindrome(s) << endl;
    return 0;
}
