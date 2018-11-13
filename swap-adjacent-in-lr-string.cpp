// trick: check the relative positions of L/R
// L can only move left, R can only move right

class Solution {
public:
    bool canTransform(string start, string end) {
        if (start.length() != end.length()) return false;
        int pstart = 0;
        int pend = 0;
        while (pstart < start.length() && pend < end.length()) {
            while (pstart < start.length() && 
                   start[pstart] != 'L' && start[pstart] != 'R') pstart ++;
             while (pend < end.length() && 
                   end[pend] != 'L' && end[pend] != 'R') pend ++;
            if (pstart == start.length() && pend == end.length()) break;
            else if (pstart == start.length() || pend == end.length()) {
                return false;
            } else {
                if (start[pstart] != end[pend]) return false;
                else {
                    if (start[pstart] == 'L' && pstart < pend) {
                        return false;
                    } else if (start[pstart] == 'R' && pstart > pend) {
                        return false;
                    } else {
                        pstart ++;
                        pend ++;
                    }
                }
            }
        }
        return true;
    }
};