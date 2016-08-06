/*
copyright xu(xusiwei1236@163.com), all right reserved.

Excel Sheet Column Title
=========================

Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 

Credits:Special thanks to @ifanchu for adding this problem and creating all test cases.
*/
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string result;
        if (n <= 0) return result;
        while (n) {
            result.insert(result.begin(), 'A' + (n-1) % 26);
            n = (n-1)/26;
        }
        return result;
    }
};

int main(int argc, char* argv[])
{
	int n = 28;

	if (argc > 1) n = atoi(argv[1]);
	cout << Solution().convertToTitle(n) << endl;
    return 0;
}
