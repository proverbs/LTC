// simple DP: O(n^3)
// O(n^2): https://leetcode.com/problems/guess-number-higher-or-lower-ii/discuss/84826/An-O(n2)-DP-Solution-Quite-Hard.

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return dfs(1, n, dp);
    }
    
    int dfs(int lt, int rt, vector<vector<int>>& dp) {
        if (lt > rt) return 0;
        if (lt == rt) return dp[lt][rt] = 0;
        int& res = dp[lt][rt];
        if (~res) return res;
        res = lt + dfs(lt + 1, rt, dp);
        for (int i = lt + 1; i <= rt; i ++) 
            res = min(res, i + max(dfs(lt, i - 1, dp), dfs(i + 1, rt, dp)));
        return res;
    }
};