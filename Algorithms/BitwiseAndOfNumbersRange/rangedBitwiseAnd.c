/*
copyright xu(xusiwei1236@163.com), all right reserved.

Bitwise AND of Numbers Range
=============================

Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

For example, given the range [5, 7], you should return 4.

Credits:
Special thanks to @amrsaqr for adding this problem and creating all test cases.
*/
#include <stdio.h>
#include <math.h>

void bitdump(int n) {
	int i;
	printf("%9d: ", n);
	for(i = 31; i >= 0; --i) {
		printf("%c", (n & (1<<i)) ? '1' : '0');
	}
	printf("\n");
}

int rangeBitwiseAnd(int m, int n) {
    int result = n, i;
#ifdef FORCE
	for(i = m; i <= n; ++i) {
		bitdump(i);
		result &= i;
	}
	return result;
#else
	int diffs = 0;
	while(m != n) {
		m >>= 1;
		n >>= 1;
		diffs++;
	}
    return m << diffs;
#endif
}

int main(int argc, char* argv[])
{
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);
	printf("%d\n", rangeBitwiseAnd(a, b));
	return 0;
}

/*
     1000: 00000000000000000000001111101000
     1001: 00000000000000000000001111101001
     1002: 00000000000000000000001111101010
     1003: 00000000000000000000001111101011
     1004: 00000000000000000000001111101100
     1005: 00000000000000000000001111101101
     1006: 00000000000000000000001111101110
     1007: 00000000000000000000001111101111
     1008: 00000000000000000000001111110000
     1009: 00000000000000000000001111110001
     1010: 00000000000000000000001111110010
     1011: 00000000000000000000001111110011
     1012: 00000000000000000000001111110100
     1013: 00000000000000000000001111110101
     1014: 00000000000000000000001111110110
     1015: 00000000000000000000001111110111
     1016: 00000000000000000000001111111000
     1017: 00000000000000000000001111111001
     1018: 00000000000000000000001111111010
     1019: 00000000000000000000001111111011
     1020: 00000000000000000000001111111100
     1021: 00000000000000000000001111111101
     1022: 00000000000000000000001111111110
     1023: 00000000000000000000001111111111
*/
