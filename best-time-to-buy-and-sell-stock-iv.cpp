// dp[i][j]: first i days, at most j transactions, maximum profits

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() == 0) return 0;
        int n = prices.size();
        k = min(k, n >> 1);
        cout << n << " " << k << endl;
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        for (int j = 1; j <= k; j ++) {
            int z = -99999999; // max(dp[p - 1][j - 1] - prices[p])
            for (int i = 1; i <= n; i ++) {
                z = max(z, dp[i][(j - 1) & 1] - prices[i - 1]);
                dp[i][j & 1] = dp[i - 1][j & 1]; // do not sell today
                dp[i][j & 1] = max(dp[i][j & 1], z + prices[i - 1]); // sell today
            }
        }
        
        return dp[n][k & 1];
    }
};