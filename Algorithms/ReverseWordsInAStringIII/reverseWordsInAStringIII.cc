/*
copyright xu(xusiwei1236@163.com), all right reserved.

Reverse Words in a String III
==============================

Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:

Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"



Note:
In the string, each word is separated by single space and there will not be any extra space in the string.
*/

#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        string result, word;
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (!isspace(c)) {
                word += c;
            } else {
                reverse(word.begin(), word.end());
                result += word + c;
                word.clear();
            }
        }
        if (word.size() > 0) {
            reverse(word.begin(), word.end());
            result += word;
        }
        return result;
    }
};

int main(int argc, char* argv[])
{
    string s = "Let's take LeetCode contest";
    if (argc > 1) s = argv[1];

    cout << "Input: " << s << endl;
    cout << "Output: " << Solution().reverseWords(s) << endl;
    return 0;
}
