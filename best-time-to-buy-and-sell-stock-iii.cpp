// dp
// dp[i]: max profit before i, sq[i]: max profit after i

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        vector<int> dp, sq;
        int left_min = prices[0];
        for (int i = 0; i < prices.size(); i ++) {
            if (left_min > prices[i]) left_min = prices[i];
            dp.push_back(prices[i] - left_min);
        }
        for (int i = 1; i < prices.size(); i ++)
            dp[i] = max(dp[i - 1], dp[i]);
        
        int right_max = prices[prices.size() - 1];
        for (int i = prices.size() - 1; i >= 0; i --) {
            if (right_max < prices[i]) right_max = prices[i];
            sq.push_back(right_max - prices[i]);
        }
        reverse(sq.begin(), sq.end());
        for (int i = prices.size() - 2; i >= 0; i --)
            sq[i] = max(sq[i + 1], sq[i]);
        
        int res = 0;
        for (int i = 0; i < prices.size(); i ++)
            res = max(res, dp[i] + sq[i]);
        return res;
    }
};