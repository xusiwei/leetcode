/*
copyright xu(xusiwei1236@163.com), all right reserved.

4Sum II
=======

Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.

To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500. All integers are in the range of -228 to 228 - 1 and the result is guaranteed to be at most 231 - 1.

Example:

Input:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]

Output:
2

Explanation:
The two tuples are:
1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0

*/
#include <assert.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        const int N = A.size();
        assert(B.size() == N && C.size() == N && D.size() == N);
        unordered_map<int, int> sumCount; // first part sum count
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int sum1 = A[i] + B[j]; // first part sum
                sumCount[sum1]++;
            }
        }
        int result = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int sum2 = C[i] + D[j]; // second part sum
                auto it = sumCount.find(-sum2);
                if (it != sumCount.end()) {
                    result += it->second;
                }
            }
        }
        return result;
    }
};

#define PRINT_VECTOR(v) \
    cout << #v << ": ["; \
    std::for_each(v.begin(), v.end(), \
        [](decltype(*v.begin()) n) { cout << n << ","; }); \
    cout <<  "]\n";

int main(int argc, char* argv[])
{
    // Input:
    // A = [ 1, 2]
    // B = [-2,-1]
    // C = [-1, 2]
    // D = [ 0, 2]
    vector<int> A{1, 2}, B{-2, -1}, C{-1, 2}, D{0, 2};
    PRINT_VECTOR(A);
    PRINT_VECTOR(B);
    PRINT_VECTOR(C);
    PRINT_VECTOR(D);
    cout << "Solutions: " << Solution().fourSumCount(A, B, C, D) << endl;
    return 0;
}
