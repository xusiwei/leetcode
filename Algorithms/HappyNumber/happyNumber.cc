/*
copyright xu(xusiwei1236@163.com), all right reserved.

Happy Number
=============

Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example:19 is a happy number


12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1


Credits:Special thanks to @mithmatt and @ts for adding this problem and creating all test cases.
*/
#include <stdlib.h>
#include <unordered_set>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> m{n};
        while (n) {
            int t = n, s = 0;
            while (t) { s += (t%10)*(t%10); t /= 10; }
            if (s == 1) return true;
            if (m.find(s) != m.end()) return false;
            m.insert(s);
            n = s;
        }
        return n > 0;
    }
};

int main(int argc, char* argv[])
{
    int n = 19;
    if (argc > 1) n = atoi(argv[1]);
    cout << Solution().isHappy(n) << endl;
    return 0;
}
