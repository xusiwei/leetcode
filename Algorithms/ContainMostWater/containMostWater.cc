/*
copyright xu(xusiwei1236@163.com), all right reseved.

Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.

*/

class Solution {
public:
    int maxArea(vector<int> &height) {
        int L = 0, R = height.size()-1;
        if(R <= 0) return 0;
        
        int res = INT_MIN;
        while(L < R) {
            res = std::max(res, std::min(height[L], height[R]) * (R - L));
            
            if(height[L] < height[R]) {
                int H = height[L]; // current lower.
                // if the picked less than current lower, then the new area must less than current.
                do {
                    L++;
                }while(L < R && height[L] < H);
            }
            else {
                int H = height[R];
                do { 
                    R--;
                }while(L < R && height[R] < H);
            }
        }
        return res;
    }
};