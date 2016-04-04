/*
copyright xu(xusiwei1236@163.com), all right reserved.

Largest Number
===============

Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.

Credits:Special thanks to @ts for adding this problem and creating all test cases.
*/
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& A) {
        vector<string> S(A.size());
        for (int i = 0; i < A.size(); i++) {
            S[i] = to_string(A[i]);
        }
        
        sort(S.begin(), S.end(), [](const string& a, const string& b) {
            return a + b > b + a;
        });
        
        string result;
        for (int i = 0; i < S.size(); i++) {
            result += S[i];
        }
        return result[0] == '0' ? "0" : result;
    }
};

int main(int argc, char* argv[])
{
    vector<int> A{3, 30, 34, 5, 9};
    if (argc > 1) A.clear();
    for (int i = 1; i < argc; i++) {
        A.push_back(atoi(argv[i]));
    }
    cout << Solution().largestNumber(A) << endl;
    return 0;
}
