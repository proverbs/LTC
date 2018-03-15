/*dp*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        int res = 0;
        int mxdp = -9999999, mxf = -9999999;
        vector<int> dp(prices.size(), -9999999);
        vector<int> f(prices.size(), -9999999);
        dp[0] = -prices[0];
        for (int i = 1; i < prices.size(); i ++) {
            if (i - 2 >= 0) mxf = max(mxf, f[i - 2]);
            if (i - 1 >= 0) mxdp = max(mxdp, dp[i - 1]);
            dp[i] = max(-prices[i], mxf - prices[i]);
            f[i] = mxdp + prices[i];
            res = max(f[i], res);
        }
        return res;
    }
};