/*
copyright xu(xusiwei1236@163.com), all right reserved.

Simplify Path
==============

Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"

click to show corner cases.
Corner Cases:

    Did you consider the case where path = "/../"?
    In this case, you should return "/".
    Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
    In this case, you should ignore redundant slashes and return "/home/foo".
*/
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string result;
        int last = 1;
        while( last < path.length() ) {
            string::size_type t = path.find('/', last); // took next slash.
            string ss = path.substr(last, t-last);
            if(ss == "." || t == last) {
                // nothing to do.
            }
            else if(ss == "..") { // for ".."
                string::size_type prev = result.find_last_of('/', t);
                if(prev != string::npos) {
                    result.erase(prev);
                }
            }
            else {
                result += "/" + ss;
            }
            if(t == string::npos) break;
            last = t+1;
        }
        return result.length() ? result : "/";
    }
};

int main(int argc, char* argv[])
{
    string path;
    while(getline(cin, path)) {
        cout << "path = \"" << path << "\", => \"" << Solution().simplifyPath(path) << "\"\n";
    }
    return 0;
}
