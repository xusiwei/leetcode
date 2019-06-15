/*
copyright xu(xusiwei1236@163.com), all right reserved.

Add Digits
==========

Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

Example:

Input: 38
Output: 2
Explanation: The process is like: 3 + 8 = 11, 1 + 1 = 2.
             Since 2 has only one digit, return it.
Follow up:
Could you do it without any loop/recursion in O(1) runtime?

*/
#include <stdlib.h>
#include <stdio.h>

class Solution {
public:
    int addDigits(int n) {
        while (n >= 10) {
            int s = 0;
            while (n) {
                s += n % 10;
                n /= 10;
            }
            n = s;
        }
        return n;
    }
};

namespace v2
{
// https://en.wikipedia.org/wiki/Digital_root
class Solution {
public:
    int addDigits(int n) {
        if (n < 10) return n;
        return (n %= 9) ? n : 9;
    }
};
} // namespace v2


int main(int argc, char* argv[])
{
    int n = argc > 1 ? atoi(argv[1]) : 38;
    printf("dr(%d): %d\n", n, Solution().addDigits(n));
    return 0;
}
