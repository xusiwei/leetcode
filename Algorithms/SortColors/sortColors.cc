/*
copyright xu(xusiwei1236@163.com), all right reserved.

Sort Colors
============

Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

click to show follow up.

Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?
*/
class Solution {
public:
    void sortColors(vector<int>& num) {
        int nc[3] = {0, 0, 0};
        
        for(int n : num) ++nc[n];
        fill(num.begin(), num.begin() + nc[0], 0);
        fill(num.begin() + nc[0], num.begin() + nc[0] + nc[1], 1);
        fill(num.begin() + nc[0] + nc[1], num.end(), 2);
    }
};

