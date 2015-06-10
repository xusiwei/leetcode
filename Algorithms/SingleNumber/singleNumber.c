/*
copyright xu(xusiwei1236@163.com), all right reserved.

Single Number
===============

Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory? 
*/
int singleNumber(int* nums, int numsSize) {
    int result = 0, i;
    for(i = 0; i < numsSize; ++i) result ^= nums[i];
    return result;
}
