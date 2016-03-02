/*
copyright xu(xusiwei1236@163.com), all right reserved.

Word Ladder
============

Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:


Only one letter can be changed at a time
Each intermediate word must exist in the word list



For example,


Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]


As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.



Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
*/
#include <assert.h>
#include <queue>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    int ladderLength(string begin, string end, unordered_set<string>& dict) {
        if (begin == end) return 0;

        unordered_map<string, int> step;
        step[begin] = 1;

        queue<string> bfsq;
        bfsq.push(begin);

        while (!bfsq.empty()) {
            string word = bfsq.front(); bfsq.pop();

            if (word == end) break;

            for (int i = 0; i < word.length(); i++) {
                string temp = word;
                for (char c = 'a'; c <= 'z'; c++) {
                    temp[i] = c;
                    if (dict.count(temp) > 0 && step.count(temp) == 0) {
                        bfsq.push(temp);
                        step[temp] = step[word] + 1;
                    }
                }
            }
        }
        return step[end];
    }
};

#if 0
// Time Limit Exceeded
//  when dict size growth, the dict element emuratating cause TLE
class Solution {
public:
    static bool like(const string& a, const string& b) {
        int count = 0;
        for (int i = 0; i < a.length(); i++) {
            if (a[i] != b[i]) {
                if (++count > 1) return false;
            }
        }
        return count == 1;
    }
    
    int ladderLength(string begin, string end, unordered_set<string>& dict) {
        if (begin == end) return 0;

        queue<string> bfsq;
        unordered_map<string, int> step;

        bfsq.push(begin);
        step[begin] = 1;
        while (!bfsq.empty()) {
            string s = bfsq.front(); bfsq.pop();
            for (auto& w: dict) {
                if (like(w, s) && step.find(w) == step.end()) {
                    bfsq.push(w);
                    step[w] = step[s] + 1;
                    if (w == end) return step[w];
                }
            }
        }
        return step[end];
    }
};
#endif

int main(int argc, char* argv[])
{
    string beg = "hit";
    string end = "cog";
    unordered_set<string> dict{"hot","dot","dog","lot","log"};
    
    if (argc > 1) beg = argv[1];
    if (argc > 2) end = argv[2];
    if (argc > 3) dict.clear();
    for (int i = 3; i < argc; i++) {
        dict.insert(argv[i]);
    }
    
    cout << Solution().ladderLength(beg, end, dict) << endl;
    return 0;
}
