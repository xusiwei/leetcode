/*
copyright xu(xusiwei1236@163.com), all right reserved.

Contains Duplicate III
=======================

Given an array of integers, find out whether there are two distinct indices i and j in the array such that the difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k.
*/
#include <stdlib.h>
#include <map>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& A, int k, int t) {
        map<int, int> dict;
        if (t < 0 || k < 0) return false;
        for (int i = 0; i < A.size(); i++) {
            // abs(A[j] - A[i]) <= t
            // => -t <= A[j] - A[i] <= t
            // => A[i] - t <= A[j] <= A[i] + t
            auto upp = dict.lower_bound(A[i] + t);
            auto low = dict.lower_bound(A[i] - t);
            if ( (upp != dict.end() && labs(i - (long)upp->second) <= k && labs(A[upp->second] - (long)A[i]) <= t)
              || (low != dict.end() && labs(i - (long)low->second) <= k && labs(A[low->second] - (long)A[i]) <= t) ) {
                return true;
            }
            dict[A[i]] = i;
        }
        return false;
    }
};

int main(int argc, char* argv[])
{
    int t = 2;
    int k = 3;
    int n = 10;
    if (argc > 1) t = atoi(argv[1]);
    if (argc > 2) k = atoi(argv[2]);
    if (argc > 3) n = atoi(argv[3]);

    vector<int> A;
    if (argc > 4) {
        for (int i = 4; i < argc; i++) {
            A.push_back(atoi(argv[i]));
        }
    } else {
        srand(time(NULL));
        for (int i = 0; i < n; i++) {
            A.push_back(rand() % (2*n));
        }
    }

    cout << "t: " << t << endl;
    cout << "k: " << k << endl;
    for (int i : A) cout << i << ", ";
    cout << endl;

    cout << Solution().containsNearbyAlmostDuplicate(A, k, t) << endl;
    return 0;
}
