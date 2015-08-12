/*
copyright xu(xusiwei1236@163.com), all right reserved.

Longest Common Prefix
======================

Write a function to find the longest common prefix string amongst an array of strings.

*/
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return string();
        int len = strs[0].length();
        for(int i = 0; i < strs.size(); ++i) {
            for(int j = 0, sz = min(len, strs[i].length()); j < sz; ++j) {
                if(strs[i][j] != strs[0][j]) {
                    len = j;
                    break;
                }
            }
        }
        return strs[0].substr(0, len);
    }
};

int main()
{
    string s;
    vector<string> strs;
    
    while(cin >> s) {
        strs.push_back(s);
    }
    
    cout << "Longest Common Prefix: " << Solution().longestCommonPrefix(strs) << endl;
}
