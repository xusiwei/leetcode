/*
copyright xu(xusiwei1236@163.com), all right reserved.

Substring with Concatenation of All Words
==========================================

You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter). 
*/

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

template<typename Vector>
void printVector(Vector v);

#define trace //printf

class Solution {
public:
    // foreach Concatenation of All Words, determine wether it is a substring of s.
    // TLE(Time Limit Exceeded)
    vector<int> findSubstringBF(string s, vector<string>& words) {
        const int size = words.size();
        
        vector<int> result;
        if(words.empty() || s.length() < words[0].length()) return result;

        vector<int> idx(words.size(), 0);
        for(int i = 0; i < size; ++i) idx[i] = i;
        
        do {
            string ss;
            for(int i = 0; i < size; ++i) ss += words[idx[i]];
            
            trace("ss: %s\n", ss.c_str());
            const char* m = strstr(s.c_str(), ss.c_str()); // REPEATED WORK !!!!
            if(m) result.push_back(m - s.c_str());
        }while(next_permutation(idx.begin(), idx.end()));
        
        return result;
    }
    
    // foreach substring, check wether it is cat by all words.
    vector<int> findSubstring(string s, vector<string>& words) {
        const int size = words.size();
        
        vector<int> result;
        if(words.empty() || s.length() < words[0].length()) return result;

        //counting words:
        // in target substring,
        // the total occurence of each word need same as dict.
        map<string, int> dict;
        for(int i = 0; i < size; ++i) {
            dict[words[i]]++;
        }
        
        //foreach substring:
        // length of target substring == words[0].length() * words.size()
        const int slen = s.length();
        const int wlen = words[0].length();
        const int tlen = wlen * size; // length of target substring.
        for(int start = 0; start + tlen <= slen; start++) {
            string ss = s.substr(start, tlen);
            
            // check wether it is cat by all words.
            int total = 0;
            map<string, int> matches;
            for(int i = 0; i + wlen <= tlen; i += wlen) {
                string w = ss.substr(i, wlen); // cut down a word.
                auto pos = dict.find(w);
                if(pos != dict.end()) { // found w in dict.
                    matches[w]++;
                    total++;
                }
                else { // not found
                    break;
                }
            }
            if(size == total && matches.size() == dict.size()) {
                auto it1 = dict.begin(), it2 = matches.begin();
                while(it1 != dict.end() && it2 != matches.end()) {
                    if(it1->second != it2->second) break;
                    it1++; it2++;
                }
                if(it1 == dict.end()) result.push_back(start);
            }
        }
        
        return result;
    }
};

template<typename Vector>
void printVector(Vector v)
{
    cout << "[";
    for(int i = 0, sz = v.size(); i < sz; i++) {
        cout << v[i] << (i+1 == sz ? "]\n" : ",");
    }
}

// "barfoofoobarthefoobarman", ["bar","foo","the"]
int main()
{
    string s, w;
    vector<string> words;
    
    cin >> s;
    while(cin >> w) {
        words.push_back(w);
    }
    printVector(words);
    cout << "s: " << s << endl;
    
    printVector(Solution().findSubstring(s, words));
    return 0;
}
