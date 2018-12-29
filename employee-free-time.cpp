// segments overlap(line sweep)
// another method is like merging k ordered array

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
    struct PX {
        int x;
        int fg;
        PX(int x, int fg) : x(x), fg(fg) {}
    };
    
    vector<PX> px;
    
    static bool cmp(const PX &a, const PX &b) {
        if (a.x == b.x) return a.fg > b.fg;
        return a.x < b.x;
    }
    
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& schedule) {
        for (int i = 0; i < schedule.size(); i ++)
            for (int j = 0; j < schedule[i].size(); j ++) {
                px.push_back(PX(schedule[i][j].start, 1));
                px.push_back(PX(schedule[i][j].end, -1));
            }
        sort(px.begin(), px.end(), cmp);
        
        vector<Interval> res;
        int st = -1, cnt = 0;
        for (int i = 0; i < px.size(); i ++) {
            if (px[i].fg == 1) {
                if (cnt == 0 && st >= 0) res.push_back({st, px[i].x}); 
                cnt ++;
            }
            else {
                cnt --;
                if (cnt == 0) st = px[i].x; 
            }
        }
        
        return res;
    }
};