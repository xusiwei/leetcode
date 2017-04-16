/*
copyright xu(xusiwei1236@163.com), all right reserved.

Optimal Division
=================

Given a list of positive integers, the adjacent integers will perform the float division. For example, [2,3,4] -> 2 / 3 / 4.

However, you can add any number of parenthesis at any position to change the priority of operations. You should find out how to add parenthesis to get the maximum result, and return the corresponding expression in string format. Your expression should NOT contain redundant parenthesis.

Example:

Input: [1000,100,10,2]
Output: "1000/(100/10/2)"
Explanation:
1000/(100/10/2) = 1000/((100/10)/2) = 200
However, the bold parenthesis in "1000/((100/10)/2)" are redundant, since they don't influence the operation priority. So you should return "1000/(100/10/2)". 

Other cases:
1000/(100/10)/2 = 50
1000/(100/(10/2)) = 50
1000/100/10/2 = 0.5
1000/100/(10/2) = 2



Note:

The length of the input array is [1, 10].
Elements in the given array will be in range [2, 1000].
There is only one optimal division for each test case.
*/

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
	string minimalDivision(vector<int>& A, int start, int N) {
		// we know that, if there is no parenthesis in expression,
		// the result is mimimal.
		// because A[0] / A[1] / A[2] / ... / A[n-1] = A[0] / (A[1] * A[2] * ... * A[n])
		if (N == 0) return "";
		string result = to_string(A[start]);
		for (int i = 1; i < N; i++) {
			result += "/" + to_string(A[start + i]);
		}
		return result;
	}

    string optimalDivisionDirectly(vector<int>& A) {
        int N = A.size();
        if (N == 0) return "";
        if (N == 1) return to_string(A[0]);
        if (N == 2) return to_string(A[0]) + "/" + to_string(A[1]);
        return to_string(A[0]) + "/(" + minimalDivision(A, 1, N-1) + ")";
    }

public:
    string optimalDivision(vector<int>& A) {
		return optimalDivisionDirectly(A);
	}
};

int main(int argc, char* argv[])
{
    vector<int> v{1000,100,10,2};
    if (argc > 1) {
        v.clear();
        for (int i = 1; i < argc; i++) {
            v.push_back(stoi(argv[i]));
        }
    }
    
    cout << "Input: ";
    for (auto i: v) {
        cout << i << ",";
    }
    cout << endl;
    cout << "Output: " << Solution().optimalDivision(v) << endl;
    
    return 0;
}
