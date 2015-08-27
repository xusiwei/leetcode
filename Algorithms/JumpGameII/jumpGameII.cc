/*
copyright xu(xusiwei1236@163.com), all right reserved.

Jump Game II
=============

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 step to the last index.)
*/
#include <limits.h>
#include <vector>
#include <iostream>
using namespace std;

#ifdef BACK
// TLE
class Solution {
public:
    int jump(vector<int>& nums) {
        const int n = nums.size();
        vector<int> step(n+1, 0);
        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] >= n-1 - i) step[i] = 1;
            else { // step[i] = 1 + min(step[i+1 : i+num[i]])
                int min = step[i+1]; // min or range [i+1 : i+num[i]]
                for(int j = 2; j < nums[i]; j++) {
                    if(step[i+j] < min) min = step[i+j];
                }
                step[i] = 1 + min;
            }
        }
        return step[0];
    }
};
#else
class Solution {
public:
    int jump(vector<int>& A) {
        int n = A.size(), step = 1;
        int currReach = A[0], nextReach = A[0];
        
        for(int i = 1; i < n; i++) {
            nextReach = max(nextReach, i + A[i]);
            if(i+1 == n) return step;
            if(i == currReach) {
                currReach = nextReach;
                step++;
            }
        }
        return 0;
    }
};
#endif

int main(int argc, char* argv[])
{
    int n;
    vector<int> nums;
    
    while(cin >> n) {
        nums.push_back(n);
    }
    
    cout << Solution().jump(nums) << endl;
    return 0;
}
