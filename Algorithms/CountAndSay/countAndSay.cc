/*
copyright xu(xusiwei1236@163.com), all right reserved.

Count and Say
==============

The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string. 
*/
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
    	const static char* tab[] = {"", "1", "11", "21", "1211", "111221"};
    	if(n <= 5) return tab[n];
        
        string result = "";
        string last = countAndSay(n-1);
        for(int i = 0; i < last.length(); ) {
	        int sames = 1;
        	while(last[i + sames] == last[i]) sames++;
        	result += "0123456789"[sames];
        	result += last[i];
        	i += sames;
        }
        return result;
    }
};

int main(int argc, char* argv[])
{
	int n = 10;
	if(argc > 1) n = atoi(argv[1]);
	
	for(int i = 1; i < n; ++i) {
		cout << Solution().countAndSay(i) << endl;
	}
	return 0;
}
