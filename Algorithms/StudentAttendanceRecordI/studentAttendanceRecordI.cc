/*
copyright xu(xusiwei1236@163.com), all right reserved.

Student Attendance Record I
============================

You are given a string representing an attendance record for a student. The record only contains the following three characters:



'A' : Absent. 
'L' : Late.
 'P' : Present. 




A student could be rewarded if his attendance record doesn't contain more than one 'A' (absent) or more than two continueL 'L' (late).    

You need to return whether the student could be rewarded according to his attendance record.

Example 1:

Input: "PPALLP"
Output: True



Example 2:

Input: "PPALLL"
Output: False
*/
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        int countA = 0, continueL = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'A') {
                countA++;
                if (countA > 1) return false;
            }
            if (s[i] == 'L') {
                continueL++;
                if (continueL > 2) return false;
            } else {
                continueL = 0;
            }
        }
        return true;
    }
};

int main(int argc, char* argv[])
{
    string s = "PPALLP";
    if (argc > 1) s = argv[1];
    
    cout << "Input: " << s << endl;
    cout << "Output: " << boolalpha << Solution().checkRecord(s) << endl;
    return 0;
}
