/*
Repeated DNA Sequences
========================

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
#include <map>

using namespace std;

class Solution {
    int toValue(char c) {
        return c == 'A' ? 0
             : c == 'C' ? 1
             : c == 'G' ? 2
             : c == 'T' ? 3
             : -1;
    }
    
    int toChar(int n) {
        return n == 0 ? 'A'
             : n == 1 ? 'C'
             : n == 2 ? 'G'
             : n == 3 ? 'T'
             : -1;
    }
    
    int encrypt(const char* str, int len) {
        int h = 0;
        for(int i = 0; i < len; ++i) {
            h <<= 2;
            h  += toValue(str[i]);
        }
//        printf("encrypt(%s): %05x\n", string(str, len).c_str(), h);
        return h;
    }
    
    string decrypt(int n, int len) {
        string res;
        for(int i = len-1; i >= 0; --i) {
            int mask = (1 << (i*2 + 2)) - 1; // 2^(2*i + 2) - 1
            char c = static_cast<char>(toChar((n & mask) >> 2*i));
//            printf("> %d %d %c\n", i, mask, c);
            res += c;
        }
//        printf("decrypt(%05x): %s\n", n, res.c_str());
        return res;
    }
    
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        map<int, int> dict;
        
        size_t length = s.length();
        for(size_t i = 0; i + 10 <= length; ++i) {
            dict[encrypt(&s[i], 10)]++;
        }
        
        for(auto it = dict.begin(); it != dict.end(); ++it) {
            if(it->second > 1) result.push_back(decrypt(it->first, 10));
        }
        return result;
    }
};

#ifdef TEST
int main(int argc, char* argv[])
{
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    auto result = Solution().findRepeatedDnaSequences(s);
    for(string s: result) {
        cout << s << endl;
    }
    return 0;
}
#endif
