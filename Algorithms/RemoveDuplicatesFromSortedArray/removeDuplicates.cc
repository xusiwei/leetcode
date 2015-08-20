/*
copyright xu(xusiwei1236@163.com), all right reserved.

Remove Duplicates from Sorted Array
====================================

Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.

*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();

        int count = 1, last = nums[0];
        for(int i = 1, sz = nums.size(); i < sz; ++i) {
            if(nums[i] != last) {
                nums[count++] = nums[i];
                last = nums[i];
            }
        }
        nums.resize(count);
        return count;
    }
};

template<typename Vector>
void printVector(Vector v)
{
    cout << "[";
    for(int i = 0, sz = v.size(); i < sz; i++) {
        cout << v[i] << (i+1 == sz ? "]\n" : ",");
    }
}

int main()
{
    int n;
    vector<int> nums;
    
    while(cin >> n) {
        nums.push_back(n);
    }
    printVector(nums);
    
    cout << Solution().removeDuplicates(nums) << ": ";
    printVector(nums);
    
    return 0;
}

