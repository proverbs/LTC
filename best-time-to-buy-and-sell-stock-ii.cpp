/*dp*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        int inf = 9999999;
        vector<int> dp(prices.size(), -inf);
        vector<int> f(prices.size(), -inf);
        dp[0] = 0;
        f[0] = -prices[0];
        for (int i = 1; i < prices.size(); i ++) {
            dp[i] = max(dp[i - 1], f[i - 1] + prices[i]);
            f[i] = max(dp[i - 1] - prices[i], f[i - 1]);
        }
        return dp[prices.size() - 1];
    }
};