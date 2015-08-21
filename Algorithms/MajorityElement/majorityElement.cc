/*
copyright xu(xusiwei1236@163.com), all right reserved.

Majority Element
====================

Given an array of size n, find the majority element. The majority element is the element that appears more than \u230a n/2 \u230b times.

You may assume that the array is non-empty and the majority element always exist in the array.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.
*/
class Solution {
public:
    int majorityElement(vector<int> &num) {
        unordered_map<int, int> dict;
        for(auto n : num) {
            dict[n]++;
        }
        int most = INT_MIN, result = 0;
        for(auto item : dict) {
            if(item.second > most) {
                most = item.second;
                result = item.first;
            }
        }
        return result;
    }
};