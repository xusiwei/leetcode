/*
copyright xu(xusiwei1236@163.com), all right reserved.

Multiply Strings
=================

Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.
*/
#include <stdio.h>
#include <assert.h>
#include <vector>
#include <iostream>
using namespace std;

#ifdef DEBUG
#define trace printf
#else
#define trace
#endif

void add(string& result, int num, int exp)
{
    trace("result: %s, num: %d, exp: %d\n", result.c_str(), num, exp);
    const int rlen = result.length();
    int acc = 0;
    
    if(num && exp > rlen) result.insert(0, exp-rlen, '0');
    for(int i = rlen-1-exp; num || acc; ) {
        if(i >= 0) {
            acc += (result[i] - '0') + num % 10;
            result[i] = (acc % 10)+'0';
            --i;
        }
        else {
            acc += num % 10;
            result.insert(result.begin(), (acc % 10)+'0');
        }
        acc /= 10;
        num /= 10;
    }
    trace("result: %s\n\n", result.c_str());
}

class Solution {
public:
    string multiply(string A, string B) {
        const int alen = A.length();
        const int blen = B.length();
        
        string result = "0";
        for(int i = alen-1; i >= 0; --i) {
            for(int j = blen-1; j >= 0; --j) {
                assert(isdigit(A[i]) && isdigit(B[j]));
                int m = (A[i] - '0') * (B[j] - '0');
                add(result, m, (alen-1-i) + (blen-1-j));
            }
        }
        
        return result;
    }
};

int main(int argc, char* argv[])
{
    string a, b;
    while(cin >> a >> b) {
        cout << Solution().multiply(a, b) << endl;
    }
    return 0;
}
