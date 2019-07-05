// classic
// SG function, game theory

class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if ((1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal)
            return false;
        vector<int> sg(1 << maxChoosableInteger, 0);
        return find(sg, (1 << maxChoosableInteger) - 1, maxChoosableInteger, desiredTotal) == 1;
    }

    int find(vector<int>& sg, int state, int n, int tot) {
        if (sg[state] != 0) return sg[state];

        for (int i = 0; i < n; i ++) {
            if ((state >> i) & 1) {
                if (tot - (i + 1) <= 0 || 
                    find(sg, state ^ (1 << i), n, tot - (i + 1)) == -1) {
                    return sg[state] = 1;
                }
            }
        }
        return sg[state] = -1;
    }
};