/*
copyright xu(xusiwei1236@163.com), all right reserved.

Generate Parentheses
======================

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"

*/

#include <stdio.h>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
		auto res = genParen(n);
		return vector<string>(res.begin(), res.end());
    }
	
	set<string> genParen(int n) {
        static map<int, set<string> > dict; // for memoried searching.
        if(dict.find(n) != dict.end()) return dict[n];
        if(0 == n) return set<string>();
        if(1 == n) return dict[1] = {"()"};
        if(2 == n) return dict[2] = {"(())", "()()"};
        if(3 == n) return dict[3] = {"((()))", "(()())", "(())()", "()(())", "()()()"};
	
		set<string> curr;
		auto last = genParen(n-1);
        for(auto s : last) { // foreach item in last: curr.add("($item)")
			curr.insert("(" + s + ")");
			for(int i = 0, len = s.length(); i < len; ++i) {
				curr.insert(s.substr(0, i) + "()" + s.substr(i, len-i));
			}
        }
        return dict[n] = curr;
	}
};

int main()
{
	vector<string> res = Solution().generateParenthesis(4);
	
	for_each(res.begin(), res.end(), [](string s) { printf("\"%s\",", s.c_str()); });
	printf("\nres.size: %zd\n", res.size());
	
	vector<string> r4{"(((())))","((()()))","((())())","((()))()","(()(()))","(()()())","(()())()","(())(())","(())()()","()((()))","()(()())","()(())()","()()(())","()()()()"};
	
	printf("r4.size: %zd\n", r4.size());
	for(int i = 0, sz = min(r4.size(), res.size()); i < sz; ++i) {
		printf("%s %s %s\n", res[i].c_str(), r4[i].c_str(), (res[i] == r4[i] ? "true" : "false"));
	}
	return 0;
}
