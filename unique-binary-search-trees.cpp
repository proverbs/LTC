/*dp*/

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, -1);
        dp[0] = dp[1] = 1;
        return dfs(n, dp);
    }

    int dfs(int x, vector<int>& dp) {
        if (dp[x] != -1) return dp[x];
        dp[x] = 0;
        for (int i = 0; i < x; i ++) {
            dp[x] += dfs(i, dp) * dfs(x - 1 - i, dp);
        }
        return dp[x];
    }
};