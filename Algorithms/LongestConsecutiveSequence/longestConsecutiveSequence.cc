/*
copyright xu(xusiwei1236@163.com), all right reserved.

Longest Consecutive Sequence
=============================

Given an unsorted array of integers, find the length of the longest consecutive elements sequence.


For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.


Your algorithm should run in O(n) complexity.
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ret = 0;
        unordered_map<int, int> m; // in a consecutive sequence[a,b], m[a] == m[b] == b-a+1
        for (int i : nums) {
            if (m.count(i) > 0) {
                continue;
            } else if (m.count(i-1) > 0 && m.count(i+1) > 0) {
                m[i] = m[i-m[i-1]] = m[i+m[i+1]] = m[i-m[i-1]] + m[i+m[i+1]] + 1;
            } else if (m.count(i-1) > 0) {
                m[i] = m[i-m[i-1]] = m[i-1] + 1;
            } else if (m.count(i+1) > 0) {
                m[i] = m[i+m[i+1]] = m[i+1] + 1;
            } else {
                m[i] = 1;
            }
            ret = max(ret, m[i]);
        }
        return ret;
    }
};
