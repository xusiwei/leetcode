/*
copyright xu(xusiwei1236@163.com), all right reseved.

Determine whether an integer is a palindrome. Do this without extra space.

click to show spoilers.
Some hints:

Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.

*/

#include <cmath> // log10, pow10
#include <cstdlib> // labs
#include <ext/numeric> // __gnu_cxx::power
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

class Solution {
public:
    bool isPalindrome(int x) {
        while(labs(x) > 10L) {
            // long near = power(10L, static_cast<long>(log10(labs(x))));
            long near = static_cast<long>( pow10(static_cast<long>(log10(labs(x)))) );
            if( (x / near) != (x % 10L) ) return false;
            x /= 10; x %= (near/10L);
            // cout << x << endl;
        }
        return true;
    }
};

#ifdef TEST
int main()
{
    int x = -2147483648;
    cin >> x;
    cout << Solution().isPalindrome(x) << endl;
    return 0;
}
#endif