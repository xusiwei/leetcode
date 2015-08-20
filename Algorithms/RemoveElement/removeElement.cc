/*
copyright xu(xusiwei1236@163.com), all right reserved.

Remove Element
================

Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length. 
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0;
        for(int i = 0, sz = nums.size(); i < sz; ++i) {
            if(nums[i] != val) {
                nums[count++] = nums[i];
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
    int val, n;
    vector<int> nums;
    
    cin >> val;
    while(cin >> n) {
        nums.push_back(n);
    }
    printVector(nums);
    cout << "val: " << val << endl;
    
    Solution().removeElement(nums, val);
    printVector(nums);
    
    return 0;
}
