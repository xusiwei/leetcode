/*
copyright xu(xusiwei1236@163.com), all right reserved.

Restore IP Addresses
=====================

Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)

Subscribe to see which companies asked this question
*/
#include <limits.h>
#include <map>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

template <typename Vector>
void printVector(Vector &v, string sep = ",") {
    cout << "[";
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << (i+1 == v.size() ? "]" : sep);
    }
}

void backtrack(map<int, vector<vector<int> > > &combineMap, vector<int> &vec) {
    if (vec.size() == 4) {
        int sum = 0;
        for (int i = 0; i < vec.size(); ++i) {
            sum += vec[i];
            //printf("%d, ", vec[i]);
        }
        //printf("\t%d\n", sum);
        if (combineMap.find(sum) == combineMap.end()) {
            combineMap[sum] = vector<vector<int> >();
        }
        combineMap[sum].push_back(vec);
        return;
    }
    
    for (int i = 1; i <= 3; i++) {
        vec.push_back(i);
        backtrack(combineMap, vec);
        vec.pop_back();
    }
}

map<int, vector<vector<int> > > combineMap;

int mapping() {
    vector<int> vec;
    backtrack(combineMap, vec);
    return 0x900dfee1;
}

int __init__ = mapping();

vector<string> split(string str, vector<int> &vec) {
    vector<string> result;
    
    int took = 0;
    string sub = str.substr(took, vec[0]);
    result.push_back(sub);
    took += vec[0];
    
    for (int i = 1; i < vec.size(); ++i) {
        sub = str.substr(took, vec[i]);
        result.push_back(sub);
        took += vec[i];
    }
    return result;
}

bool isNumber(string str) {
    if (str.length() > 1 && str.find_first_not_of('0') != 0) {
        return false;
    }
    stringstream ss(str);
    int num = INT_MAX;
    return ss >> num && 0 <= num && num <= 255;
}

bool valid(vector<string> &ip) {
    for (int i = 0; i < ip.size(); ++i) {
        if (!isNumber(ip[i])) {
            return false;
        }
    }
    return true;
}

string join(vector<string> &vec) {
    string result = vec[0];
    for (int i = 1; i < vec.size(); ++i) {
        result += "." + vec[i];
    }
    return result;
}

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        vector< vector<int> > combines = combineMap[s.length()];
        for (int i = 0; i < combines.size(); ++i) {
            vector<string> ip = split(s, combines[i]);
            if (valid(ip)) {
                result.push_back(join(ip));
            }
        }
        return result;
    }
};

int main(int argc, char* argv[])
{
    string str = "25525511135";
    if (argc > 1) str = argv[1];
    vector<string> ips = Solution().restoreIpAddresses(str);
    printVector(ips, "\n");
    return 0;
}
