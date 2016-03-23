/*
copyright xu(xusiwei1236@163.com), all right reserved.

Word Break II
==============

Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.



Return all such possible sentences.



For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].



A solution is ["cats and dog", "cat sand dog"].
*/
#include <vector>
#include <string>
#include <unordered_set>
#include <iostream>
using namespace std;

#if 1
// memorized DFS
// from https://leetcode.com/discuss/33884/11ms-c-solution-concise
// by samoshka
class Solution {
    unordered_map<string, vector<string>> m;

    vector<string> combine(string word, vector<string> prev){
        for(int i=0;i<prev.size();++i){
            prev[i]+=" "+word;
        }
        return prev;
    }

public:
    vector<string> wordBreak(string s, unordered_set<string>& dict) {
        if(m.count(s)) return m[s]; //take from memory
        vector<string> result;
        if (dict.count(s)) { //a whole string is a word
            result.push_back(s);
        }
        for(int i = 1; i < s.size(); ++i){
            string word = s.substr(i);
            if (dict.count(word)) {
                string rem = s.substr(0, i);
                vector<string> prev = combine(word, wordBreak(rem, dict));
                result.insert(result.end(), prev.begin(), prev.end());
            }
        }
        m[s] = result; //memorize
        return result;
    }
};
#else
// Time Limit Exceeded
class Solution {
    void backtrack(const string& s, const unordered_set<string>& dict,
        vector<string>& result, string& line, int start) {
        if (start == s.length()) {
            if (line.back() == ' ') line.resize(line.length()-1); // turncate ending space.
            result.push_back(line);
        }

        for (int e = start+1; e <= s.length(); e++) {
            string word = s.substr(start, e-start);
            if (dict.count(word) > 0) {
                string temp = line;
                line += word;
                line += " ";
                backtrack(s, dict, result, line, e);
                line = temp;
            }
        }
    }

public:
    vector<string> wordBreak(string s, unordered_set<string>& dict) {
        vector<string> result;
        string line;

        backtrack(s, dict, result, line, 0);
        return result;
    }
};
#endif

template <typename Vector>
void printVector(const Vector& list) {
    for (int i = 0; i < list.size(); i++) {
        cout << list[i] << endl;
    }
}

int main(int argc, char* argv[])
{
    string s = "catsanddog";
    unordered_set<string> dict{"cat", "cats", "and", "sand", "dog"};

    printVector(Solution().wordBreak(s, dict));
    return 0;
}
