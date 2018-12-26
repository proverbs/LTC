// no need to binary search, just scan from left to right

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
        int lt = bin_sea_lt(intervals, newInterval);
        int rt = bin_sea_rt(intervals, newInterval);
        // merge [lt, rt]
        vector<Interval> res;
        if (rt == -1) {
            res.push_back(newInterval);
            for (int i = 0; i < intervals.size(); i ++) res.push_back(intervals[i]);
        }
        else if (lt == intervals.size()) {
            for (int i = 0; i < intervals.size(); i ++) res.push_back(intervals[i]);
            res.push_back(newInterval);
        } else if (lt - 1 == rt) {
            vector<Interval> z;
            if (newInterval.end < intervals[lt].start) {
                z.push_back(newInterval);
                z.push_back(intervals[lt]);
            } else if (newInterval.start > intervals[lt].end) {
                z.push_back(intervals[lt]);
                z.push_back(newInterval);
            } else {
                z.push_back(Interval(min(newInterval.start, intervals[lt].start), max(newInterval.end, intervals[lt].end)));
            }
            for (int i = 0; i < intervals.size(); i ++) {
                if (i == lt) {
                    for (int j = 0; j < z.size(); j ++) {
                        res.push_back(z[j]);
                    }
                } else {
                    res.push_back(intervals[i]);
                }
            }
        } else {
            for (int i = 0; i < intervals.size(); i ++) {
                if (i <= lt || i > rt) res.push_back(intervals[i]);
                if (i == lt) {
                    res.back().start = min(intervals[i].start, newInterval.start);
                }
                if (i == rt) {
                    res.back().end = max(intervals[i].end, newInterval.end);
                }
            }
        }
        
        return res;
    }
    
    int bin_sea_lt(vector<Interval>& intervals, Interval newInterval) {
        int lt = 0, rt = intervals.size() - 1, res = intervals.size();
        while (lt <= rt) {
            int mid = lt + rt >> 1;
            if (intervals[mid].end >= newInterval.start) res = mid, rt = mid - 1;
            else lt = mid + 1;
        }
        return res;
    }
    
    int bin_sea_rt(vector<Interval>& intervals, Interval newInterval) {
        int lt = 0, rt = intervals.size() - 1, res = -1;
        while (lt <= rt) {
            int mid = lt + rt >> 1;
            if (intervals[mid].start <= newInterval.end) res = mid, lt = mid + 1;
            else rt = mid - 1;
        }
        return res;
    }
};