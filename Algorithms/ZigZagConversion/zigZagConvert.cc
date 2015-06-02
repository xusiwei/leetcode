/*
copyright xu(xusiwei1236@163.com), all right reseved.

 The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);

convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR". 
*/

class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows == 1) return s;

        int cur = 0, delta = 1;
        vector<string> bufs((size_t)nRows);
        for (int i=0; i<s.length(); ++i) {
            bufs[cur] += s[i];
            cur += delta;
            int r = (i+1) % (2*nRows-2); // next row
            if (r == nRows-1 || r == 0) delta = -delta;
        }

        string res;
        for (int i=0; i<nRows; i++) {
            res += bufs[i];
        }

        return res;
    }
};
