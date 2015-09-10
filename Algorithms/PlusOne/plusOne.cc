/*
copyright xu(xusiwei1236@163.com), all right reserved.

Plus One
=========

Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int acc = 1;
        vector<int> result(digits);
        for(int i = result.size()-1; i >= 0; i--) {
            acc += result[i];
            result[i] = acc % 10;
            acc /= 10;
            if(acc == 0) break;
        }
        if(acc) result.insert(result.begin(), acc);
        return result;
    }
};