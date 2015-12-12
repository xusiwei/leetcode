/*
copyright xu(xusiwei1236@163.com), all right reserved.

Largest Rectangle in Histogram
===============================

Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10.
*/
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <stack>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    // invariant:
    //   if L is the left index of largest rectangle, then H[L-1] < H[L] (L > 0)
    // because, if H[L-1] >= H[L], area[L-1:R] > area[L:R]
    int largestRectangleArea(vector<int>& H) {
        if (H.size() == 0) return 0;
        stack<int> candidates; // left side candidates.
        
        H.push_back(0);
        int maxArea = 0;
        for (int i = 0; i < H.size(); ) {
            if (candidates.empty() || H[i] >= H[candidates.top()]) {
                candidates.push(i);
                i++;
            } else {
                int top = candidates.top();
                candidates.pop();
                int area = H[top] * (candidates.empty() ? i : i - candidates.top() - 1);
                if (area > maxArea) {
                    maxArea = area;
                }
            }
        }
        
        return maxArea;
    }
    
#if 0
    // O(n^2) Time Limited Error(TLE)
    int LRA02(vector<int>& H) {
        int maxArea = INT_MIN;
        for (int i = 0; i < H.size(); ++i) {
            int minH = H[i];
            for (int j = i + 1; j < H.size(); ++j) {
                if (H[j] < minH) minH = H[j];
                int area = (j - i + 1) * minH;
                //printf("%d: %d, %d: %d, area: %d\n", i, H[i], j, H[j], area);
                if (area > maxArea) {
                    maxArea = area;
                }
            }
        }
        return maxArea;
    }    
    
    // O(n^3) Time Limited Error(TLE)
    int LRA03(vector<int>& H) {
        int maxArea = INT_MIN;
        for (int i = 0; i < H.size(); ++i) {
            for (int j = i + 1; j < H.size(); ++j) {
                int minH = INT_MAX;
                for (int k = i; k <= j; k++) {
                    if (H[k] < minH) {
                        minH = H[k];
                    }
                }
                int area = (j - i + 1) * minH;
                //printf("%d: %d, %d: %d, area: %d\n", i, H[i], j, H[j], area);
                if (area > maxArea) {
                    maxArea = area;
                }
            }
        }
        return maxArea;
    }
#endif
};

int main(int argc, char* argv[])
{
    vector<int> vec;
    for (int i = 1; i < argc; ++i) {
        vec.push_back(atoi(argv[i]));
    }
    cout << Solution().largestRectangleArea(vec) << endl;
    return 0;
}

