/*
copyright xu(xusiwei1236@163.com), all right reserved.

Factorial Trailing Zeroes
==========================

Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.

Credits:Special thanks to @ts for adding this problem and creating all test cases.
*/
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        // represent n as 5-based:
        //  n = a0 * 5^0  +  a1 * 5^1  + a2 * 5^2 ...
        int b = 1;
        vector<int> base;
        vector<int> pow5;
        while (n) {
            base.push_back(n%5);
            pow5.push_back(b);
            // cout << n%5 << "\t" << b << endl;
            n /= 5;
            b *= 5;
        }
        int count = 0;
        for (int i = 1; i < base.size(); i++) {
            for (int j = i, e = 0; j < base.size(); j++, e++) {
                count += base[j] * pow5[e];
                // cout << base[j] << "*" << pow5[e] << endl;
            }
        }
        return count;
    }
};

int main(int argc, char* argv[])
{
    int n = 199;
    if (argc > 1) n = atoi(argv[1]);
    cout << Solution().trailingZeroes(n) << endl;
    return 0;
}
