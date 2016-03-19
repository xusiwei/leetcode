/*
copyright xu(xusiwei1236@163.com), all right reserved.

Palindrome Partitioning II
===========================

Given a string s, partition s such that every substring of the partition is a palindrome.


Return the minimum cuts needed for a palindrome partitioning of s.


For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/
#include <limits.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        const int n = s.length();
        if (n == 0) return 0;

        // p[i] := palindrome(s[i...j])
        vector<vector<bool>> p(n, vector<bool>(n, false));
        vector<int> c(n, INT_MAX); // c[i] := minCut(s[i...n-1])
        for (int i = n-1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (j-i == 0 || j-i == 1 && s[j] == s[i]
                 || s[j] == s[i] && p[i+1][j-1]) {
                    p[i][j] = true;
                    if (j == n-1) {
                        c[i] = 0;
                    } else if (c[j+1] + 1 < c[i]) { // [i...j] [j+1...n-1]
                        c[i] = c[j+1] + 1;
                    }
                }
            }
        }
        return c[0];
    }
};

#if 0
// Time Limit Exceeded
class Solution {
public:
    bool palindrome(const string& s, int b, int e) {
        if (b > e) return false;
        for (e--; b < e; b++, e--) {
            if (s[b] != s[e]) return false;
        }
        return true;
    }   

    void backtrack(int& r, const string& s, int n, int cuts, int last) {
        if (last == n) {
            r = min(r, cuts);
        }

        for (int i = last+1; i <= n; i++) { // forward scan
        // for (int i = n; i > last; i--) { // backward scan
            if (palindrome(s, last, i)) {
                cuts++;
                backtrack(r, s, n, cuts, i);
                cuts--;
            }
        }
    }

    int minCut(string s) {
        if (palindrome(s, 0, s.length())) return 0;

        int result = INT_MAX;
        backtrack(result, s, s.length(), -1, 0);
        return result;
    }
};
#endif


int main(int argc, char* argv[])
{
    string s = "aabac";
    if (argc > 1) s = argv[1];
    cout << Solution().minCut(s) << endl;
    return 0;
}
