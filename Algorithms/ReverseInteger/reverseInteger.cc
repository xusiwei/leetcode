/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

click to show spoilers.
Have you thought about this?

Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

Update (2014-11-10):
Test cases had been added to test the overflow behavior.
*/

#include <cmath>
#include <iostream>
using namespace std;

class Solution {
public:
    // a[0], b[0] is the most important digit.
    int cmopare(int a[], int b[], int len) {
        for(int i = 0; i < len; ++i) {
            if(a[i] == b[i]) continue;
            else if(a[i] < b[i]) return -1;
            else return 1;
        }
        return 0;
    }
    
    int reverse(int x) {
        static int MAX[] = {2, 1, 4, 7, 4, 8, 3, 6, 4, 7}; // reverse of max
        int buffer[16], count=0, sign=1;
        if(x < 0) {
            sign = -1;
            MAX[9] = 8;
        }
        
        // buf[0] is the most inimportant.
        while(x) {
            buffer[count++] = std::abs(x%10);
            x /= 10;
        }
        
        // humm.. overflow.
        if(count == 10 && cmopare(buffer, MAX, 10) > 0) return 0;
        for(int i=0; i<count; i++) {
            x = x*10 + sign*buffer[i];
        }
        return x;
    }
};

#ifdef TEST
int main()
{
    int x = -2147483648;
    cin >> x;
    cout << Solution().reverse(x);
}
#endif
