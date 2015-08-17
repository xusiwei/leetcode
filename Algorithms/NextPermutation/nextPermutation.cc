/*
copyright xu(xusiwei1236@163.com), all right reserved.

Next Permutation
================
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 ¡ú 1,3,2
3,2,1 ¡ú 1,2,3
1,1,5 ¡ú 1,5,1

*/
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        if(size <= 1) return;
        
        for(int i = size-1; i >= 1; --i) {
            if(nums[i-1] < nums[i]) {
                int j = size;
                while(!(nums[i-1] < nums[--j])) ;
                swap(nums[i-1], nums[j]);
                reverse(nums.begin() + i, nums.end());
                return;
            }
        }
        reverse(nums.begin(), nums.end());
    }
};

template<typename Vector>
void printVector(Vector v)
{
    for(int i = 0, sz = v.size(); i < sz; i++) {
        cout << v[i] << (i+1 == sz ? "\n" : " ");
    }
}
#define PrintVector(v) printVector(v)

int main(int argc, char* argv[])
{
    int n;
    vector<int> nums;
    
    while(cin >> n) {
        nums.push_back(n);
    }
    
    sort(nums.begin(), nums.end());
    vector<int> ivec(nums.begin(), nums.end());
    do {
        PrintVector(ivec);
        PrintVector(nums); Solution().nextPermutation(nums); cout << "\n";
    }while(next_permutation(ivec.begin(), ivec.end()));
    return 0;
}
