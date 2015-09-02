/*
copyright xu(xusiwei1236@163.com), all right reserved.

Insert Interval
================

Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
*/

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
    // case 1       case 2       case 3
    // +--+  .. +---+  ...       +---+
    //            +----------+
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> result;
        auto it = intervals.begin();
        for(; it != intervals.end(); it++) {
            if(it->start > newInterval.end) break; // case 3.
            if(it->end >= newInterval.start) { // case 2.
                newInterval.start = min(newInterval.start, it->start);
                newInterval.end   = max(newInterval.end  , it->end);
            }
            else result.push_back(*it); // case 1.
        }
        result.push_back(newInterval); // merged interval.
        result.insert(result.end(), it, intervals.end());
        return result;
    }
};
