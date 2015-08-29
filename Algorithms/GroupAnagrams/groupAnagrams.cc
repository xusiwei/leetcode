/*
copyright xu(xusiwei1236@163.com), all right reserved.

Group Anagrams
===============

Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]

Note:

    For the return value, each inner list's elements must follow the lexicographic order.
    All inputs will be in lower-case.

Update (2015-08-09):
The signature of the function had been updated to return list<list<string>> instead of list<string>, as suggested here. If you still see your function signature return a list<string>, please click the reload button to reset your code definition. 
*/
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, int> index;
        for(auto& str: strs) {
            string s = str;
            sort(s.begin(), s.end());
            auto it = index.find(s);
            if(it != index.end()) {
                auto& L = result[index[s]];
                auto pos = lower_bound(L.begin(), L.end(), str);
                L.insert(pos, str);
            }
            else {
                index.insert(make_pair(s, result.size()));
                result.push_back(vector<string>(1u, str));
            }
        }
        sort(result.begin(), result.end(), 
            [](const vector<string>& a, const vector<string>& b) {
                return a.size() < b.size();
            });
        return result;
    }
};

template<typename Vector>
void printVector(Vector v)
{
    cout << "[";
    for(int i = 0, sz = v.size(); i < sz; i++) {
        cout << v[i] << (i+1 == sz ? "]" : ",");
    }
}

template<typename Matrix>
void printMatrix(Matrix m)
{
    cout << "[";
    for(int i = 0, isz = m.size(); i < isz; i++) {
        printVector(m[i]);
        cout << (i+1 == isz ? "]\n" : ",\n");
    }
}

int main(int argc, char* argv[])
{
    string s;
    vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
    
    while(cin >> s) strs.push_back(s);
    printMatrix(Solution().groupAnagrams(strs));
    return 0;
}
