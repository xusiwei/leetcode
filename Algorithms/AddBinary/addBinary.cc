/*
copyright xu(xusiwei1236@163.com), all right reserved.

Add Binary
===========

Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100". 
*/
class Solution {
public:
    string addBinary(string a, string b) {
        int acc = 0;
        int alen = a.length();
        int blen = b.length();
        int mlen = max(alen, blen);
        string result(mlen, ' ');
        
        for(int i = 1; i <= mlen; i++) {
            int b1 = alen-i >= 0 ? (a[alen-i] - '0') : 0;
            int b2 = blen-i >= 0 ? (b[blen-i] - '0') : 0;
            acc += b1 + b2;
            result[mlen-i] = "01"[acc&1]; // acc % 2
            acc >>= 1; // acc /= 2
        }
        if(acc) result.insert(result.begin(), "01"[acc&1]);
        return result;
    }
};
