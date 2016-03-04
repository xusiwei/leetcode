/*
copyright xu(xusiwei1236@163.com), all right reserved.

Word Ladder II
===============

Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:


Only one letter can be changed at a time
Each intermediate word must exist in the word list



For example,


Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]


Return

  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]




Note:

All words have the same length.
All words contain only lowercase alphabetic characters.
*/
#include <limits.h>
#include <queue>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    void findPaths(unordered_multimap<string, string> &parents,
                   vector<vector<string>> &result,
                   string start,
                   string current,
                   vector<string>& path) {
        if (current == start) {
            vector<string> r(path.rbegin(), path.rend());
            result.push_back(r);
            return;
        }
        auto er = parents.equal_range(current);
        for (auto it = er.first; it != er.second; it++) {
            path.push_back(it->second);
            findPaths(parents, result, start, it->second, path);
            path.pop_back();
        }
    }
    
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string>> result;
        if (start == end) return result;
        
        unordered_multimap<string, string> parents;
        
        unordered_set<string> level[3];
        unordered_set<string>* previousLevel = &level[0];
        unordered_set<string>* currentLevel = &level[1];
        unordered_set<string>* nextLevel = &level[2];
        currentLevel->insert(start);
        
        bool complete = false;
        while (!complete) {
            nextLevel->clear();
            for (auto it = currentLevel->begin(); it != currentLevel->end(); it++) {
                for (int i = 0; i < it->length(); i++) {
                    string temp = *it;
                    for (char c = 'a'; c <= 'z'; c++) {
                        temp[i] = c;
                        if (temp == end) {
                            complete = true;
                            parents.insert(make_pair(temp, *it));
                        } else if (dict.count(temp) > 0
                            && currentLevel->count(temp) == 0
                            && previousLevel->count(temp) == 0) {
                            nextLevel->insert(temp);
                            parents.insert(make_pair(temp, *it));
                        }
                    }
                }
            }
            if (nextLevel->empty()) break;
            auto p = previousLevel;
            previousLevel = currentLevel;
            currentLevel = nextLevel;
            nextLevel = p;
        }
        if (complete) {
            vector<string> path{end};
            findPaths(parents, result, start, end, path);
        }
        return result;
    }
};

#if 0
// Wrong Answer
//
// on a typical BFS step,
// we extends each node to the near by nodes which not marked, then mark it up.
//
// so, the mark sequence is a typical Tree(each node only one parent)
// 
// but, if we want to get more than one best path, we need makes
//  each node more than one parent node.
//
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
    
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string>> result;
        if (start == end) return result;

        queue<string> bfsq;
        unordered_set<string> mark;
        unordered_map<string, string> parent; // parent node on BFS tree

        int steps = INT_MAX;
        bfsq.push(start);
        mark.insert(start);

        // ensure dict not contain both start and end.
        dict.erase(start);
        dict.erase(end);
        while (!bfsq.empty()) {
            string word = bfsq.front(); bfsq.pop();

            if (word == end || like(word, end)) {
                vector<string> path{end};
                if (word != end && word != start) {
                    path.insert(path.begin(), word);
                }
                for (auto p = parent.find(word); p != parent.end(); p = parent.find(p->second)) {
                    path.insert(path.begin(), p->second);
                }
                if (word == start) path.insert(path.begin(), start);
                if (path.size() <= steps) {
                    steps = path.size();
                } else {
                    break;
                }
                result.push_back(path);
            }

            //cout << "> " << word << endl;
            for (int i = 0; i < word.length(); i++) {
                string temp = word;
                for (char c = 'a'; c <= 'z'; c++) {
                    temp[i] = c;
                    if (dict.count(temp) > 0 && mark.count(temp) == 0) {
                        bfsq.push(temp);
                        mark.insert(temp);
                        parent[temp] = word;
                    }
                }
            }
        }
        return result;
    }
};
#endif

template<typename Matrix>
void printMatrix(Matrix m)
{
    for(int i = 0; i < m.size(); i++) {
        for(int j = 0; j < m[i].size(); j++) {
            cout << m[i][j] << ", ";
        }
        cout << "\n";
    }
    cout << endl;
}

int main(int argc, char* argv[])
{
//     string beg = "hit";
//     string end = "cog";
//     unordered_set<string> dict{"hot","dot","dog","lot","log"};
    string beg = "red";
    string end = "tax";
    unordered_set<string> dict{"ted","tex","red","tax","tad","den","rex","pee"};
    
    if (argc > 1) beg = argv[1];
    if (argc > 2) end = argv[2];
    if (argc > 3) dict.clear();
    for (int i = 3; i < argc; i++) {
        dict.insert(argv[i]);
    }
    printMatrix(Solution().findLadders(beg, end, dict));
    return 0;
}
