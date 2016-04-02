/*
copyright xu(xusiwei1236@163.com), all right reserved.

Fraction to Recurring Decimal
==============================

Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

For example,

Given numerator = 1, denominator = 2, return "0.5".
Given numerator = 2, denominator = 1, return "2".
Given numerator = 2, denominator = 3, return "0.(6)".




  No scary math, just apply elementary math knowledge. Still remember how to perform a long division?
  Try a long division on 4/9, the repeating part is obvious. Now try 4/333. Do you see a pattern?
  Be wary of edge cases! List out as many test cases as you can think of and test your code thoroughly.


Credits:Special thanks to @Shangrila for adding this problem and creating all test cases.
*/
#include <stdlib.h>
#include <set>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string result;
        int64_t n = numerator;
        int64_t d = denominator;

        if (n * d < 0) result += "-";

        n = n > 0 ? n : -n;
        d = d > 0 ? d : -d;
        stringstream ss;
        ss << n / d;
        result += ss.str();

        if (n %= d) {
            result += ".";
            int64_t n0 = n;
            unordered_map<int, int> index;
            vector<int> r; // remainder
            vector<int> q; // quotient
            int start = 0; // repeating start point
            do {
                int rem = n*10 % d;
                q.push_back(n*10 / d);
                r.push_back(rem);
                n = rem;
                if (n == n0) break;
                if (index.count(rem) > 0) {
                    start = index[rem];
                    break;
                }
                index[rem] = q.size();
            } while (n != 0);
            string fpart;
            for (int i = 0; i < r.size(); i++) {
                // if (n && i == start) fpart += "(";
                fpart += to_string(q[i]);
            }
            if (n) {
                fpart.insert(start, "(");
                fpart += ")";
            }
            result += fpart;
        }
        return result;
    }
};

int main(int argc, char* argv[])
{
    int n = 5;
    int d = 7;

    if (argc > 1) n = atoi(argv[1]);
    if (argc > 2) d = atoi(argv[2]);

    cout << n << endl;
    cout << d << endl;
    cout << Solution().fractionToDecimal(n, d) << endl;
    return 0;
}
