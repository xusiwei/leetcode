/*
Split Assembled Strings
========================

Given a list of strings, you could assemble these strings together into a loop.
Among all the possible loops, you need to find the lexicographically biggest string after cutting
and making one breakpoint of the loop, which will make a looped string into a regular one.

So, to find the lexicographically biggest string, you need to experience two phases:

    Assemble all the strings into a loop, where you can reverse some strings or not and connect them in the same order as given.
    Cut and make one breakpoint in any place of the loop, which will make a looped string into a regular string starting from
	the character at the cutting point.

And your job is to find the lexicographically biggest one among all the regular strings.

Example:

Input: "abc", "xyz"
Output: "zyxcba"
Explanation: You can get the looped string "-abcxyz-", "-abczyx-", "-cbaxyz-", "-cbazyx-", 
where '-' represents the looped status. 
The answer string came from the fourth looped one, 
where you could cut from the middle and get "zyxcba".

Note:

    The input strings will only contain lowercase letters.
    The total length of all the strings will not over 1000.
*/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution
{
public:
    string splitLoopedString(vector<string>& strs)
    {
        vector<string> rvec;
        for (int i = 0; i < strs.size(); i++) {
            auto s = strs[i];
            reverse(s.begin(), s.end());
            rvec.push_back(s);
        }

        string base;
        vector<int> id, head;
        for (int i = 0; i < strs.size(); i++) {
            int last = base.size();
            base += max(strs[i], rvec[i]);
            id.resize(base.size(), i);
            head.resize(base.size(), last);
        }

        string result = "";
        for (int i = 0; i < base.size(); i++) {
            auto str = base, rev = base, w = strs[id[i]];
            str.replace(head[i], w.size(), w);
            auto s = str.substr(i) + str.substr(0, i);

            reverse(w.begin(), w.end());
            rev.replace(head[i], w.size(), w);
            auto r = rev.substr(i) + rev.substr(0, i);

            result = max(result, max(s, r));
        }

        return result;
    }
};

int main(int argc, char* argv[])
{
    vector<string> v{ "abc", "xyz" };
    if (argc > 1) {
        v.clear();
        for (int i = 1; i < argc; i++) {
            v.push_back(argv[i]);
        }
    }

    for (auto& s : v) {
        cout << s << ",";
    }
    cout << endl;
    cout << Solution().splitLoopedString(v) << endl;
    return 0;
}
