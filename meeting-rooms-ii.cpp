// tipical


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
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.size() == 0) return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        // priority_queue<int> end_time; // largest is the top
        priority_queue<int, vector<int>, greater<int>> end_time; // least is the top
        end_time.push(0);
        for (int i = 0; i < intervals.size(); i ++) {
            int et = end_time.top();
            cout << et << endl;
            if (et <= intervals[i].start) {
                end_time.pop();
            }
            // add a room
            end_time.push(intervals[i].end);
        }
        return end_time.size();
    }
    
    static bool cmp(const Interval& a, const Interval& b) { // IMPORTANT: should be static!!!
        return a.start < b.start;
    }
};