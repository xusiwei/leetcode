/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2 
*/

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> res;
        unordered_map<int, int> toIndex;
        
        int sz = numbers.size();
        for(int i=0; i<sz; ++i) {
            int v = numbers[i];
            unordered_map<int, int>::iterator pos = toIndex.find(target - v);
            if(pos != toIndex.end()) {
                int a = pos->second + 1, b = i + 1;
                if(a > b) std::swap(a, b);
                res.push_back(a);
                res.push_back(b);
                return res;
            }
            toIndex.insert(make_pair(v, i));
        }
        return res;
    }
};