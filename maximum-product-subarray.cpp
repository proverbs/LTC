/*dp*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        vector<int> f(nums.size(), 0);
        int res;
        res = dp[0] = f[0] = nums[0];
        for (int i = 1; i < nums.size(); i ++) {
            if (nums[i] > 0) {
                dp[i] = max(dp[i - 1] * nums[i], nums[i]);
                f[i] = min(f[i - 1] * nums[i], nums[i]);
            } else {
                dp[i] = max(f[i - 1] * nums[i], nums[i]);
                f[i] = min(dp[i - 1] * nums[i], nums[i]);
            }
            res = max(dp[i], res);
        }
        return res;
    }
};