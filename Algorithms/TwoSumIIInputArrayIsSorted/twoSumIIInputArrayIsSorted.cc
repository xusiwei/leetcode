/*
copyright xu(xusiwei1236@163.com), all right reserved.

Two Sum II Input Array Is Sorted
================================

Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.

Note:

Your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution and you may not use the same element twice.
Example:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.

*/
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& A, int target) {
        unordered_map<int, int> index;
        const int N = A.size();
        for (int i = 0; i < N; i++) {
            int n = A[i];
            auto it = index.find(target - n);
            if (it != index.end()) {
                return {it->second + 1, i + 1};
            }
            index[n] = i;
        }
        return {};
    }
};

int main(int argc, char* argv[])
{
    vector<int> vi{2,7,11,15};
    auto ans = Solution().twoSum(vi, 9);
    if (ans.size()) cout << ans[0] << "," << ans[1] << endl;
    return 0;
}
