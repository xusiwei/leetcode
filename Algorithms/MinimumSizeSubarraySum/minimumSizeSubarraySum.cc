/*
copyright xu(xusiwei1236@163.com), all right reserved.

Minimum Size Subarray Sum
==========================

Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.


For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.


click to show more practice.

More practice:

If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).
*/
#include <limits.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int sum, vector<int>& A) {
        const int n = A.size();
        vector<int> S(n+1, 0);
        for (int i = 0; i < n; i++) {
            S[i+1] = S[i] + A[i];
        }

        int result = INT_MAX;
        for (int i = 1; i <= n; i++) {
            if (S[i] >= sum) {
                int p = upper_bound(S.begin(), S.begin() + i, S[i] - sum) - S.begin();
                result = min(result, i - p + 1);
            }
        }
        return result == INT_MAX ? 0 : result;
    }
};

int main(int argc, char* argv[])
{
    int s = 7;
    vector<int> v{2,3,1,2,4,3};

    if (argc > 1) s = atoi(argv[1]);
    if (argc > 2) {
        s = 0;
        v.clear();
        srand(time(NULL));
        int n = atoi(argv[2]);
        for (int i = 0; i < n; i++) {
            int r = (rand() >> 3) % n;
            v.push_back(r);
            s += r;
            cout << r << ", ";
        }
        s = static_cast<int>(rand()%120*100.0 * s);
    }

    for (int i : v) cout << i << ", ";
    cout << "\ns: " << s << endl;

    cout << Solution().minSubArrayLen(s, v) << endl;
    return 0;
}
