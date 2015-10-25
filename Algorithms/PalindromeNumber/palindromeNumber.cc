/*
copyright xu(xusiwei1236@163.com), all right reserved.

Palindrome Number
==================

Determine whether an integer is a palindrome. Do this without extra space.

click to show spoilers.
Some hints:

Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.

*/

#include <cmath> // log10, pow
#include <cstdio>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;

        int len = (int)log10(x) + 1;
        for(int i = 0, j = len-1; i < j; i++, j--) {
            int a = x / (int)pow(10, i) % 10;
            int b = x / (int)pow(10, j) % 10;
            if(a != b) return false;
        }
        return true;
    }
};

#ifdef TEST
int main()
{
    int x;
    cin >> x;
    cout << Solution().isPalindrome(x) << endl;
    return 0;
}
#endif
