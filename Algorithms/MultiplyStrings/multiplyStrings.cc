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

template<typename Vector>
void printVector(Vector v);

int add(vector<int>& buffer, int num, int exp)
{
//    printf("num: %d, exp: %d\n", num, exp); printVector(buffer);
    int i, acc = 0;
    for(i = exp; num || acc; ++i) {
        acc += buffer[i] + num % 10;
        buffer[i] = acc % 10;
        acc /= 10;
        num /= 10;
    }
//    printVector(buffer); puts("");
    return i;
}

class Solution {
public:
    string multiply(string A, string B) {
        const int alen = A.length();
        const int blen = B.length();
        vector<int> buffer(alen * blen, 0);
        
        int len;
        for(int i = alen-1; i >= 0; --i) {
            for(int j = blen-1; j >= 0; --j) {
                assert(isdigit(A[i]) && isdigit(B[j]));
                int m = (A[i] - '0') * (B[j] - '0');
                len = add(buffer, m, (alen-1-i) + (blen-1-j));
            }
        }
        
        string result;
        int i = len-1;
        while(0 == buffer[i]) --i;
        for(; i >= 0; --i) {
            result += "0123456789"[buffer[i]];
        }
        
        return result.length() ? result : "0";
    }
};

template<typename Vector>
void printVector(Vector v)
{
    for(int i = 0, sz = v.size(); i < sz; i++) {
        cout << v[i] << (i+1 == sz ? "\n" : " ");
    }
}

int main(int argc, char* argv[])
{
    string a, b;
    while(cin >> a >> b) {
        cout << Solution().multiply(a, b) << endl;
    }
    return 0;
}
