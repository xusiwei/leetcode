/*
copyright xu(xusiwei1236@163.com), all right reserved.

Single Number III
=================

Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

Example:

Input:  [1,2,1,3,2,5]
Output: [3,5]
Note:

The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
*/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int axb = 0; // result of XOR all ints, is a XOR b
        for (int n: nums) axb ^= n;

        // rightmost 1-bit diff between a and b
        int diff = axb & (-axb);

        int a = 0;
        for (int n: nums) {
            if (n & diff) a ^= n;
        }
        return {a, axb ^ a};
    }
};

template <typename T>
void printVector(const vector<T>& v)
{
    for (T t: v) cout << t << ", ";
    cout << endl;
}

int main(int argc, char* argv[])
{
    vector<int> v{1, 2, 1, 3, 2, 5};
    vector<int> r = Solution().singleNumber(v);
    printVector(v);
    printVector(r);
    return 0;
}
