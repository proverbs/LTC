/*dp*/

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector<int> dp(nums.size(), 0);
        vector<int> f(nums.size(), 0);
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); i ++) {
            dp[i] = f[i - 1] + nums[i];
            f[i] = max(f[i - 1], dp[i - 1]);
        }
        return max(dp[nums.size() - 1], f[nums.size() - 1]);
    }
};