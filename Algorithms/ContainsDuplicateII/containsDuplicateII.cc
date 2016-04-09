/*
copyright xu(xusiwei1236@163.com), all right reserved.

Contains Duplicate II
======================

Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& A, int k) {
        unordered_map<int, int> dict;
        for (int i = 0; i < A.size(); i++) {
            auto it = dict.find(A[i]);
            if (it != dict.end() && i - it->second <= k) {
                return true;
            }
            dict[A[i]] = i;
        }
        return false;
    }
};
