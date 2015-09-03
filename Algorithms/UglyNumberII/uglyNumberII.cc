/*
copyright xu(xusiwei1236@163.com), all right reserved.

Ugly Number II
===============

Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number.

Hint:

The naive approach is to call isUgly for every number until you reach the nth one. Most numbers are not ugly. Try to focus your effort on generating only the ugly ones.
An ugly number must be multiplied by either 2, 3, or 5 from a smaller ugly number.
The key is how to maintain the order of the ugly numbers. Try a similar approach of merging from three sorted lists: L1, L2, and L3.
Assume you have Uk, the kth ugly number. Then Uk+1 must be Min(L1 * 2, L2 * 3, L3 * 5).
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/

#include <stdio.h>
// #include <algorithm>
// using namespace std;

int nthUglyNumber(int n) {
    static int tab[] = {1, 2, 3, 4, 5, 6, 8, 9, 10, 12};
    if(n <= sizeof(tab)/sizeof(tab[0])) return tab[n-1];
    
    // by hand:
	// 6 = 3 * 2
	// 8 = 4 * 2
	// 9 = 3 * 3
	// 10 = 5 * 2
	// 12 = 6 * 2
	// 16 = 8 * 2
	
	//     5    3    2
	// 1:  0    0    0
	// 2:  0    0    1
	// 3:  0    1    0
	// 4:  0    0    2
	// 5:  1    0    0
	// 6:  0    1    0
	// 8:  0    0    3
	// 9:  0    2    0
	//10:  1    0    1
	//12:  0    1    2
	//15:  1    1    0
	
	
	// {2, 3, 5}
	// => {2(1), 3, 4, 5}
	// => {2(1), 3(1), 4, 5, 6}
	// => {2(1), 3(1), 4(1), 5, 6, 8}
	// => {2(1), 3(2), 4(1), 5, 6, 8, 9}
	// => {2(1), 3(2), 4(1), 5(1), 6, 8, 9, 10}
	// => {2(1), 3(2), 4(2), 5(1), 6, 8, 9, 10, 12} 	// => {2(1), 3(2), 4(1), 5(2), 6(1), 8, 9, 10, 15}
	// => {2(1), 3(2), 4(2), 5(2), 6, 8, 9, 10, 12, 15}
	// => {2(1), 3(2), 4(2), 5(2), 6, 8(1), 9, 10, 12, 15, 16}
	// => {2(1), 3(2), 4(2), 5(2), 6, 8(1), 9(1), 10, 12, 15, 16, 18}
	

    vector<int> buffer{2, 3, 5};
	int idx[3] = {0};

    
    return min;
}

int main(int argc, char* argv[])
{
    return 0;
}
