/*
copyright xu(xusiwei1236@163.com), all right reserved.

Single Number II
==================

Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory? 
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> dict;
        for(int n : nums)
            if(++dict[n] == 3)
                dict.erase(n);
        return dict.begin()->first;
    }
};
