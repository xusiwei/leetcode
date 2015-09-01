/*
copyright xu(xusiwei1236@163.com), all right reserved.

Merge Intervals
================

Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size() <= 1) return intervals;
        vector<Interval> result(intervals);
        
        sort(result.begin(), result.end(),
            [](const Interval& a, const Interval& b){
                return a.start < b.start;
            });
        int count = 0, size = intervals.size();
        for(int i = 1; i < size; i++) {
            if(result[count].end < result[i].start) result[++count] = result[i];
            else { result[count].end = max(result[count].end, result[i].end); }
        }
        result.resize(count+1);
        return result;
    }
};

int main(int argc, char* argv[])
{
    vector<Interval> in{{1,3}, {2,6}, {5, 7}, {8,10}, {15,18}};
    vector<Interval> out = Solution().merge(in);
    for_each(out.begin(), out.end(),
        [](const Interval& i) {
            cout << "[" << i.start << "," << i.end << "], ";
        });
    return 0;
}
