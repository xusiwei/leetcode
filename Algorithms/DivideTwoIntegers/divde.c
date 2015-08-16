/*
copyright xu(xusiwei1236@163.com), all right reserved.

Divide Two Integers
=====================

Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT. 
*/
#include <stdio.h>
#include <limits.h>

#ifdef DEBUG
#define trace printf
#else
#define trace
#endif

int divide(int num, int divisor) {
    int result = 0;
    int sign = 0;
    unsigned unum, udiv, acc, factor;
    
    if(num == divisor) return 1;
    if(divisor == INT_MIN) return 0;
    if(divisor == 0 || (num == INT_MIN && divisor == -1)) return INT_MAX;
    
    unum = num < 0     ? -num     : num;
    udiv = divisor < 0 ? -divisor : divisor;
    if((0x80000000u & (unsigned)num) != (0x80000000u & (unsigned)divisor)) sign = 1;
    
    acc = udiv;
    factor = 1;
    while((acc<<1) < unum) { // && (acc<<1) < (UINT_MAX<<2u)
        acc = (acc<<1);
        factor <<= 1;
    }
    
    while(unum >= udiv) {
        unum -= acc;
        result += factor;
        trace("$ %d %d, %d %d\n", num, result, acc, factor);
        while(unum < acc) {
            acc >>= 1;
            factor >>= 1;
        }
    }
    return sign ? -result : result;
}

int main()
{
    int n, d, r;
    
    while(scanf("%d%d", &n, &d) == 2) {
        r = divide(n, d);
        printf("div(%d,%d): %d\n", n, d, r);
        
        printf("    %d/%d : ", n, d);
        if((INT_MIN == n && -1 == d) || 0 == d)
            printf("%s\n", "overflow");
        else printf("%d\n", n/d);
    }
    return 0;
}
