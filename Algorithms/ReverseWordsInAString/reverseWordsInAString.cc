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
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

// Programming Pearls, Handwaving algorithm
class Solution {
public:
    void reverseWords(string &s) {
        if (s.length() == 0) return;
        
        string result = "";
        
        if (s[s.length()-1] == ' ') {
            int last = s.find_last_not_of(' ') + 1;
            s.erase(last, s.length() - last);
        }
        
        int first = s.find_first_not_of(' ', 0);
        while (first != string::npos) {
            int wend = s.find(' ', first);  // word end
            if (wend == string::npos) wend = s.length();
            
            string word = s.substr(first, wend - first);
            reverse(word.begin(), word.end());
            result += word;
                        
            first = s.find_first_not_of(' ', wend); // next word
            if (first == string::npos) break;
            
            result += ' ';
        }
        reverse(result.begin(), result.end());
        s.swap(result);
    }
};

int main(int argc, char* argv[])
{
    string s = "  the  sky  is  blue  ";
    cout << "\"" << s << "\"" << endl;
    Solution().reverseWords(s);
    cout << "\"" << s << "\"" << endl;
    return 0;
}
