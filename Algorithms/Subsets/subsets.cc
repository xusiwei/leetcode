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
        if (rand() % 2) {
            return subsets1(S);
        } else {
            return subsets2(S);
        }
    }
    
    vector<vector<int> > subsets1(vector<int> &S) {
        vector<bool> mask(S.size(), false);
        
        sort(S.begin(), S.end());
        
        while(1) {
            // generate current subset by mask.
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
    
    vector<vector<int> > subsets2(vector<int> &S) {
        vector<vector<int> > result;
        vector<int> t;
        int n = S.size();
        for (int k = 0; k <= n; ++k) {
            vector<vector<int> > c;
            combine(c, S, n, k, t);
            result.insert(result.end(), c.begin(), c.end());
        }
        return result;
    }
    
    void combine(vector<vector<int> >& out, vector<int>& v, int n, int k, vector<int>& t) {
        if (k == 0) {
            vector<int> cp(t);
            sort(cp.begin(), cp.end());
            out.push_back(cp);
        } else {
            for (int i = 0; i < n; ++i) {
                t.push_back(v[i]);
                combine(out, v, i, k-1, t);
                t.pop_back();
            }
        }
    }
};

