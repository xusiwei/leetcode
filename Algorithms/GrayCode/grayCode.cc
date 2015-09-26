/*
copyright xu(xusiwei1236@163.com), all right reserved.

Gray Code
==========

The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2

Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.
*/
// 4 do by hand:
//   0 0000 -
//   1 0001 --
//   3 0011
//   2 0010 ---
//   6 0110
//   7 0111
//   5 0101
//   4 0100 ----
//  12 1100
//  13 1101
//  15 1111
//  14 1110
//  10 1010
//  11 1011
//   9 1001
//   8 1000 -----
class Solution {
public:
    vector<int> grayCode(int n) {
        if(0 == n) return vector<int>(1, 0); // null set.
        vector<int> result{0, 1};
        if(1 == n ) return result;
        
        for(int i = 1; i < n; ++i) {
            int mask = 1 << i;
            for(int j = 0; j < mask; j++) {
                result.push_back(result[mask-1-j] | mask);
            }
        }
        return result;
    }
};
