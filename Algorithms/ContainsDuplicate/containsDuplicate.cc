/*
copyright xu(xusiwei1236@163.com), all right reserved.

Contains Duplicate
===================

Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> dict;
        for (int i : nums) {
            if (dict.count(i) > 0) return true;
            dict.insert(i);
        }
        return false;
    }
};
