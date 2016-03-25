/*
copyright xu(xusiwei1236@163.com), all right reserved.

Compare Version Numbers
========================

Compare two version numbers version1 and version2.
If version1  version2 return 1, if version1  version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:
0.1  1.1  1.2  13.37

Credits:Special thanks to @ts for adding this problem and creating all test cases.
*/
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int compareVersion(string v1, string v2) {
        size_t len1 = v1.length(), len2 = v2.length();
        size_t s1 = 0, s2 = 0;
        
        while (s1 < len1 && s2 < len2) {
            size_t e1 = v1.find_first_of('.', s1);
            size_t e2 = v2.find_first_of('.', s2);
            int n1 = stoi(v1.substr(s1, e1), NULL, 10);
            int n2 = stoi(v2.substr(s2, e2), NULL, 10);
            if (n1 < n2) return -1;
            if (n1 > n2) return 1;
            s1 = e1 != string::npos ? e1+1 : len1;
            s2 = e2 != string::npos ? e2+1 : len2;
        }
        
        bool zeros = true; // we assume all of tailing are zeros
        string rem = s1 != len1 ? v1.substr(s1) : v2.substr(s2);
        for (int i = 0; i < rem.length(); i++) {
            if (rem[i] != '.' && rem[i] != '0') {
                zeros = false;
                break;
            }
        }
        if (zeros) return 0;
        return s1 != len1 ? 1 : -1;
    }
};

int main(int argc, char* argv[])
{
    string s1 = "1.0.0.0";
    string s2 = "1.0";
    
    if (argc > 1) s1 = argv[1];
    if (argc > 2) s2 = argv[2];
    
    cout << s1 << endl;
    cout << s2 << endl;
    cout << Solution().compareVersion(s1, s2) << endl;
    return 0;
}
