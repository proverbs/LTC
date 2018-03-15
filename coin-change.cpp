/*dp，背包*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, 9999999);
        dp[0] = 0;
        for (int i = 1; i <= amount; i ++) {
            for (int j = 0; j < coins.size(); j ++) {
                dp[i] = i - coins[j] >= 0 ? min(dp[i], dp[i - coins[j]] + 1) : dp[i];
            }
        }
        return dp[amount] == 9999999 ? -1 : dp[amount];
    }
};