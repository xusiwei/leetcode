/*
copyright xu(xusiwei1236@163.com), all right reserved.

Subsets
=========

Given a set of distinct integers, nums, return all possible subsets.

Note:

    Elements in a subset must be in non-descending order.
    The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<vector<int> > res;
        vector<bool> mask(S.size(), false);
        
        sort(S.begin(), S.end());
        
        while(1) {
            // recorde current subset by mask.
            int true_count=0;
            vector<int> cur;
            for(int i=0; i<mask.size(); i++) {
                if(mask[i]) {
                    true_count++;
                    cur.push_back(S[i]);
                }
            }
            res.push_back(cur);
        
            if(true_count == S.size()) break;

            // generate next subset mask. simulate +1.
            for(int i=0; i<mask.size(); i++) {
                if(!mask[i]) { mask[i] = true; break; }
                else { mask[i] = false; continue; }
            }
        }
        return res;
    }
};
