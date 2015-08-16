/*
copyright xu(xusiwei1236@163.com), all right reserved.

Integer to Roman
=================

Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
*/

#include <stdlib.h>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        struct nc {
            int  n; // number
            char c; // char
            int  t; // times
        }tab[] = { // refers to: https://en.wikipedia.org/wiki/Roman_numerals
            {1000, 'M'}, {500, 'D'}, {100, 'C'}, {50, 'L'}, {10, 'X'}, {5, 'V'}, {1, 'I'}
        };
        int TABN = sizeof(tab) / sizeof(nc);

        for(int i = 0; i < TABN; i++) {
            tab[i].t = num / tab[i].n;
            num %= tab[i].n;
        }

        string res;
        for(int i = 0; i < TABN; i++) {
            if(tab[i].t) {
                if(tab[i].t == 1 && tab[i+1].t == 4) { // VIIII -> IX, 1*5 + 4*1 == -1*1 + 1*10
                    res += tab[i+1].c;
                    res += tab[i-1].c;
                    i++;
                }
                else if(tab[i].t == 4) { // IIII -> IV
                    res += tab[i].c;
                    res += tab[i-1].c;
                }
                else { // I, II, III, etc.
                    res += string(tab[i].t, tab[i].c);
                }
            }
        }
        return res;
    }
};

int main(int argc, char* argv[])
{
    int start = 1, end = 3999;
    if(argc > 2) {
        start = atoi(argv[1]);
        end   = atoi(argv[2]);
    }
    
    for(int i = start; i <= end; ++i) {
        cout << i << ": " << Solution().intToRoman(i) << endl;
    }
    
    return 0;
}

