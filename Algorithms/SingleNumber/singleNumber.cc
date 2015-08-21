/*
copyright xu(xusiwei1236@163.com), all right reserved.

Single Number
===============

Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory? 
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        
        unordered_set<int> iset;
        unordered_set<int>::iterator it;
        for(int i = 0, sz = nums.size(); i < sz; i++) {
            it = iset.find(nums[i]);
            if( it != iset.end() ) {
                iset.erase(it);
            }
            else {
                iset.insert(nums[i]);
            }
        }
        return *iset.begin(); 
    }
};
