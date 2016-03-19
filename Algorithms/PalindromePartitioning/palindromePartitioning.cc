/*
copyright xu(xusiwei1236@163.com), all right reserved.

Palindrome Partitioning
========================

Given a string s, partition s such that every substring of the partition is a palindrome.


Return all possible palindrome partitioning of s.


For example, given s = "aab",

Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool palindrome(const string& s, int b, int e) {
        if (b > e) return false;
        for (e--; b < e; b++, e--) {
            if (s[b] != s[e]) return false;
        }

        return true;
    }

    void backtrack(vector<vector<string>>& r, const string& s, int n,
                    vector<string>& parts, int last, int k) {
        if (k == n) {
            r.push_back(parts);
            // cout << endl;
        }

        for (int i = k+1; i <= n; i++) {
            if (palindrome(s, last, i)) {
                parts.push_back(s.substr(last, i-last));
                // cout << "push " << s.substr(last, i-last) << ", ";
                backtrack(r, s, n, parts, i, i);
                parts.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        if (s.length() == 0) return result;

        vector<string> part;
        backtrack(result, s, s.length(), part, 0, 0);
        return result;
    }
};

template <typename Matrix>
void printMatrix(const Matrix& mat) {
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[i].size(); j++) {
            cout << mat[i][j] << ", ";
        }
        cout << endl;
    }
}

int main(int argc, char* argv[])
{
    string s = "aabac";
    if (argc > 1) s = argv[1];
    printMatrix(Solution().partition(s));
    return 0;
}
