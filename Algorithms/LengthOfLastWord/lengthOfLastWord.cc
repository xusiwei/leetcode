/*
copyright xu(xusiwei1236@163.com), all right reserved.

Length of Last Word
====================

Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.
*/
#include <ctype.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0, last = 0;
        for(int i = 0; i < s.length(); i++) {
            if(isalpha(s[i])) last = ++len;
            else len = 0;
        }
        return last;
    }
};

int main(int argc, char* argv[])
{
    string line;
    while(getline(cin, line)) {
        cout << Solution().lengthOfLastWord(line) << endl;
    }
    return 0;
}
