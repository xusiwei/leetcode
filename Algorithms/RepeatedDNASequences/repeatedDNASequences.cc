/*
copyright xu(xusiwei1236@163.com), all right reserved.

Repeated DNA Sequences
=======================

All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.


For example,

Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        unordered_map<string, int> dict;
        
        for(int i = 0, last = s.length() - 10; i <= last; ++i) {
            string sub = s.substr(i, 10);
            if (++dict[sub] == 2) {
                result.push_back(sub);
            }
        }
        return result;
    }
};

int main(int argc, char* argv[])
{
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    auto result = Solution().findRepeatedDnaSequences(s);
    for(string s: result) {
        cout << s << endl;
    }
    return 0;
}
