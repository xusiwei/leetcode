/*
copyright xu(xusiwei1236@163.com), all right reserved.

Letter Combinations of a Phone Number
======================================

Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.
![mobile phone keyboard mapping](http://upload.wikimedia.org/wikipedia/commons/thumb/7/73/Telephone-keypad2.svg/200px-Telephone-keypad2.svg.png)

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

Note:
Although the above answer is in lexicographical order, your answer could be in any order you want. 
*/

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

#ifdef DEBUG
#define trace printf
#else
#define trace
#endif

class Solution {
public:
    vector<string> combineProxy(const char* digs) {
        static const char* mapping[] = {
            "", // 0
            "", // 1
            "abc", // 2
            "def", // 3
            "ghi", // 4
            "jkl", // 5
            "mno", // 6
            "pqrs", // 7
            "tuv", // 8
            "wxyz", // 9
        };
    
        vector<string> result;
        
        if(digs[0] == '\0') return result;
        
        int num = digs[0] - '0';
        assert(0 <= num && num <= 9);
        const char* str = mapping[num];
        int len = strlen(str);
        
        if(digs[1] == '\0') {
            for(int i = 0; i < len; ++i) {
                result.push_back(string(1, str[i]));
            }
            return result;
        }
        
        vector<string> last = combineProxy(digs + 1);
        for(int i = 0; i < len; ++i) {
            trace("get %c from %d\n", str[i], num);
            for(int j = 0, sz = last.size(); j < sz; ++j) {
                trace(" add %c + %s\n", str[i], last[j].c_str());
                result.push_back(str[i] + last[j]);
            }
        }
        
        return result;
    }

    vector<string> letterCombinations(string digits) {
        return combineProxy(digits.c_str());
    }
};

int main()
{
    string digs;
    Solution().letterCombinations("");
    while(cin >> digs) {
        auto result = Solution().letterCombinations(digs);
        cout << "{";
        for_each(result.begin(), result.end(), [](string s){ cout << s << ","; });
        cout << "}\n";
    }
    return 0;
}
