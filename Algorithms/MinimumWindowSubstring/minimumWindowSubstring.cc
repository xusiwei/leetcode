/*
copyright xu(xusiwei1236@163.com), all right reserved.

Minimum Window Substring
=========================

Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"

Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the empty string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S. 
*/
#include <limits.h> // INT_MAX
#include <deque>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string minWindow(string S, string T) {
        if(S.length() == 0 || T.length() == 0 || S.length() < T.length()) return "";
        
        int target[256] = {0};
        for(int i = 0; i < T.length(); i++) {
            target[T[i]]++;
        }
        
        int minLen = INT_MAX, minBeg = -1;
        int window[256] = {0}, count = 0;
        
        // imagining, the two side of the window is slidable.
        // algorithm:
        //  step 1. sliding right side of the window;
        //  step 2. if current window is big enough, goto step 3; else continue step 1;
        //  step 3. sliding left side of the window, makes it as smaller as possible;
        deque<int> sides; // buffer to cache sides.
        for(int i = 0; i < S.length(); i++) { // i indicates right side of window.
            char c = S[i];
            if(target[c] > 0) { // char at the sides of the window must exists in T.
                sides.push_back(i);
                
                window[c]++;
                if(window[c] <= target[c]) {
                    count++;
                }
                
                if(count >= T.length()) {
                    // sliding left side, makes window smaller.
                    int left = sides.front();
                    while(window[S[left]] > target[S[left]] && !sides.empty()){
                        sides.pop_front();
                        window[S[left]]--; // next time, S[left] is out of window.
                        left = sides.front(); // slide left side.
                    }
                    
                    // counting minimum window.
                    if(i - left + 1 < minLen) {
                        minLen = i - left + 1;
                        minBeg = left;
                    }
                }
            }
        }
        if(minBeg < 0) return "";
        return S.substr(minBeg, minLen);
    }
};

int main(int argc, char* argv[])
{
    string S = "ADOBECODEBANC"; 
    string T = "ABC";
    
    if(argc > 2) {
        S = argv[1];
        T = argv[2];
    }
    
    cout << "minWindow:\n>" << S << "\n>" << T << "\n" << Solution().minWindow(S, T) << endl;
    return 0;
}
