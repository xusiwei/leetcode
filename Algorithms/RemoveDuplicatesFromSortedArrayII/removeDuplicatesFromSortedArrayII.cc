/*
copyright xu(xusiwei1236@163.com), all right reserved.

Remove Duplicates from Sorted Array II
=======================================

Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length. 
*/
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& num) {
        if(num.size() <= 2) return num.size();
        int last = 0, count = 1;
        for(int i = 1; i < num.size(); i++) {
            if(num[i] != num[last]) {
                num[++last] = num[i];
                count = 1;
            }
            else if(++count == 2) { // num[i] == num[last]
                num[++last] = num[i];
            }
        }
        num.resize(last+1);
        return num.size();
    }
};

int main(int argc, char* argv[])
{
    vector<int> num{1,1,1,2,2,3};
    
    if(argc > 1) {
        num.clear();
        for(int i = 1; i < argc; i++) {
            num.push_back(atoi(argv[i]));
        }
    }
    
    int resized = Solution().removeDuplicates(num);
    for(int i = 0; i < resized; i++) {
        cout << num[i] << ", ";
    }
    cout << endl;
    return 0;
}
