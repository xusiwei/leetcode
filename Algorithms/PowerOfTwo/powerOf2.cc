/*
Power of Two
==============

Given an integer, write a function to determine if it is a power of two.

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        
        int found = false;
        for(int i = 30; i >= 0; i--) {
            if(n & (1<<i)) {
                if(!found) found = true;
                else return false;
            }
        }
        return true;
    }
};
