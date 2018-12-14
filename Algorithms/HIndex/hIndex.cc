/*
copyright xu(xusiwei1236@163.com), all right reserved.

H Index
=======

Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."

Example:

Input: citations = [3,0,6,1,5]
Output: 3
Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each of them had
             received 3, 0, 6, 1, 5 citations respectively.
             Since the researcher has 3 papers with at least 3 citations each and the remaining
             two with no more than 3 citations each, her h-index is 3.
Note: If there are several possible values for h, the maximum one is taken as the h-index.
*/

#include <vector>
#include <algorithm>
#include <iostream>

using std::max;
using std::cout;
using std::sort;
using std::vector;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.empty()) return 0;
        vector<int> A(citations);
        sort(A.begin(), A.end());
        int hindex = 0, count = 0;
        for (int i = (int)A.size() - 1; i >= 0; i--) {
            count++;
            if (A[i] >= count) {
                hindex = max(hindex, count);
            }
        }
        return hindex;
    }
};

int main(int argc, char* argv[])
{
    vector<int> citations{3,0,6,1,5};
    cout << "citations: [";
    std::for_each(citations.begin(), citations.end(),
        [](int c) { cout << c << ","; });
    cout << "]\nH-Index: " << Solution().hIndex(citations) << "\n";
    return 0;
}
