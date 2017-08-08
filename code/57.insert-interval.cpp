/*
 * [57] Insert Interval
 *
 * https://leetcode.com/problems/insert-interval
 *
 * algorithms
 * Hard (27.47%)
 * Total Accepted:    97.7K
 * Total Submissions: 355.1K
 * Testcase Example:  '[[1,3],[6,9]]\n[2,5]'
 *
 * Given a set of non-overlapping intervals, insert a new interval into the
 * intervals (merge if necessary).
 * 
 * You may assume that the intervals were initially sorted according to their
 * start times.
 * 
 * 
 * Example 1:
 * Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
 * 
 * 
 * 
 * Example 2:
 * Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as
 * [1,2],[3,10],[12,16].
 * 
 * 
 * 
 * This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
 * 
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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;

        int i = 0;
        for (; i < intervals.size() && intervals[i].end < newInterval.start; ++i)
            res.push_back(intervals[i]);

        res.push_back(newInterval);
        int size = res.size();

        for (; i < intervals.size() && res[size - 1].end >= intervals[i].start; ++i) {
            res[size - 1].start = min(res[size - 1].start, intervals[i].start);
            res[size - 1].end = max(res[size - 1].end, intervals[i].end);
        }

        for (; i < intervals.size(); ++i)
            res.push_back(intervals[i]);

        return res;
    }
};
