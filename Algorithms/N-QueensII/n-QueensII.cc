/*
copyright xu(xusiwei1236@163.com), all right reserved.

N-Queens II
============

Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.


*/

class Solution {
    int n;
public:
    void solve(int& res, vector<int>& cur) {
        int iq = static_cast<int>(cur.size()) - 1;
        for(int i = 0; i < iq; i++) {
            if(cur[i] == cur[iq]
            || abs(i - iq) == abs(cur[i] - cur[iq])) return;
        }

        if(iq == n-1) {
            ++res;
        }

        for(int i = 0; i < n; i++) {
            cur.push_back(i);
            solve(res, cur);
            cur.pop_back(); // backtrack
        }
    }

    int totalNQueens(int n) {
        int res;
        vector<int> cur;
        this->n = n;
        solve(res, cur);
        return res;
    }
};