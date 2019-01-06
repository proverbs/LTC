// description: Given an array of cards with numbers wrriten on both sides and an infinite number of card flips, 
// find the minimum number appearing on any card's back which is not appearing on any card's front.

class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        int n = 2001;
        vector<int> cs(n, 0);
        
        for (int i = 0; i < backs.size(); i ++) {
            if (fronts[i] == backs[i]) cs[fronts[i]] = -2222;
            else {
                cs[fronts[i]] ++;
                cs[backs[i]] ++;
            }
        }
        
        for (int i = 1; i < n; i ++)
            if (cs[i] > 0) return i;
        return 0;
    }
};