/*
copyright xu(xusiwei1236@163.com), all right reserved.

Roman to Integer
====================

Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/
#include <iostream>
#include <string>
using namespace std;

static int value[256];

class Solution {
public:
    Solution() {
        // refers to: https://en.wikipedia.org/wiki/Roman_numerals
        value['I'] = 1;
        value['V'] = 5;
        value['X'] = 10;
        value['L'] = 50;
        value['C'] = 100;
        value['D'] = 500;
        value['M'] = 1000;
    }

    // I  II  III  IV  V  VI  VII  VIII  IX  X
    // XI XII XIII XIV XV XVI XVII XVIII XIX XX
    int romanToInt(string s) {
        if(s.length() == 0) return 0;
        int res = 0;
        for (int i=0; i<s.length(); ++i) {
            int v = value[s[i]]; // current value
            if(i < s.length()-1) { // not last char
                int nv = value[s[i+1]]; // next value
                if(v >= nv) res += v;
                else {
                    res += (nv - v); // IV, IX, etc.
                    ++i;
                }
            }
            else res += v; // last
        }
        return res;
    }
};

int main()
{
    string roman;
    while(cin >> roman) {
        cout << roman << ": " << Solution().romanToInt(roman) << endl;
    }
}
