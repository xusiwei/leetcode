/*
copyright xu(xusiwei1236@163.com), all right reserved.

Next Greater Element III
=========================

Given a positive 32-bit integer n, you need to find the smallest 32-bit integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive 32-bit integer exists, you need to return -1.

Example 1:

Input: 12
Output: 21



Example 2:

Input: 21
Output: -1
*/

#include <limits.h>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
    int nextGreaterElement(int n)
    {
        vector<int> digits;

        string buffer = to_string(n);
        next_permutation(buffer.begin(), buffer.end());

        long result = stol(buffer);
        if (result > INT_MAX || result <= (long)n) {
            return -1;
        }
        return result;
    }
};

int main(int argc, char* argv[])
{
    int n = 1234;
    if (argc > 1) n = stoi(argv[1]);

    cout << "Input: " << n << endl;
    cout << "Output: " << Solution().nextGreaterElement(n) << endl;
    return 0;
}
