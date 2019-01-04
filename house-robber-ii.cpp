// dp

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (!n) return 0;
        if (n == 1) return nums[0];
        
        vector<vector<int>> dp(n, vector<int>(2, 0));
        // not rob the first house
        dp[0][0] = 0;
        dp[0][1] = -99999999;
        for (int i = 1; i < n; i ++) {
            dp[i][1] = dp[i - 1][0] + nums[i];
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        }
        int res = max(dp[n - 1][0], dp[n - 1][1]);
        // rob the first house, cannot rob the last house
        dp[0][0] = 0;
        dp[0][1] = nums[0];
        for (int i = 1; i < n; i ++) {
            dp[i][1] = dp[i - 1][0] + nums[i];
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        }
        res = max(dp[n - 1][0], res);
        
        return res;
    }
};