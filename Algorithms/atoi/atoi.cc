/*
copyright xu(xusiwei1236@163.com), all right reserved.

Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button to reset your code definition.

spoilers alert... click to show requirements for atoi.
*/

#include <cctype>
#include <climits>
#include <iostream>

using namespace std;

struct Exception
{
    const char* hint_;
    Exception(const char* hint = NULL) : hint_(hint) {}
    const char* what() { return hint_; }
};

class Solution {
public:
    int myAtoi(string str) {
        long val = 0, sign = 1;
        const char* p = str.c_str();
        
        while(isspace(*p)) p++; // skip prefix white chars.
        
        if(*p == '+') p++;
        else if(*p == '-') {
            p++;
            sign = -1;
        }
        
        if(!isdigit(*p)) return 0; // throw Exception("bad format");
        for(; *p; p++) {
            if(!isdigit(*p)) break; // throw Exception("bad format");
            val = val*10 + sign*(*p - '0');
            if(val > INT_MAX) return INT_MAX;
            if(val < INT_MIN) return INT_MIN;
        }
        return val;
    }
};
#ifdef TEST
int main()
{
    string str;
    cin >> str;
    try{
        cout << Solution().myAtoi(str) << endl;
    }
    catch(Exception e) {
        cerr << "catch a " << e.what() << endl;
    }
    return 0;
}
#endif
