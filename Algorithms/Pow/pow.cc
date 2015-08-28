/*
copyright xu(xusiwei1236@163.com), all right reserved.

Pow
====

Implement pow(x, n). 
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0 || x == 1.0) return 1.0;
        if(x == -1.0) return n & 1 ? -1.0 : 1.0;
        
        bool sign = false;
        if(n < 0) {
            sign = true;
            n = -n;
        }
        
        double result = 1.0;
        while(n) { // refers std::power
            if(n & 1) result *= x;
            n >>= 1;
            x  *= x;
        }
        
        return sign ? 1.0/result : result;
    }
};

int main(int argc, char* argv[])
{
    double x = 2.0;
    int n = 10;
    
    if(argc > 1) x = atof(argv[1]);
    if(argc > 2) n = atoi(argv[2]);
    
    printf("Pow(%lf, %d): %lf\n", x, n, Solution().myPow(x, n));
    return 0;
}
