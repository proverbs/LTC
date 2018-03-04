/*monotonicity*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<Interval> res;
        if (intervals.empty()) return res;
        int rt = intervals[0].end;
        int lt = intervals[0].start;
        for (int i = 1; i < intervals.size(); i ++) {
            if (intervals[i].start <= rt) rt = max(rt, intervals[i].end);
            else {
                res.push_back(Interval(lt, rt));
                lt = intervals[i].start;
                rt = intervals[i].end;
            }
        }
        res.push_back(Interval(lt, rt));
        return res;
    }

    static bool cmp(const Interval& a, const Interval& b) {
        return a.start < b.start;
    }
};