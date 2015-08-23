/*
copyright xu(xusiwei1236@163.com), all right reserved.

Trapping Rain Water
====================

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
*/

#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int trap(vector<int>& H) {
        int result = 0;
        int left = 0, right = H.size()-1;
        int lmax = 0, rmax = 0;
        while(left < right) {
            if(H[left] <= H[right]) {
                if(H[left] >= lmax) lmax = H[left];
                else result += lmax - H[left];
                left++;
            }
            else {
                if(H[right] >= rmax) rmax = H[right];
                else result += rmax - H[right];
                right--;
            }
        }
        return result;
    }
};

int main(int argc, char* argv[])
{
    int n;
    vector<int> H;
    
    while(cin >> n) {
        H.push_back(n);
    }
    cout << "size:" << H.size() << endl;
    
    cout << Solution().trap(H) << endl;
    return 0;
}
