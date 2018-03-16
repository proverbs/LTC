/*dp, 01背包*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i ++) sum += nums[i];
        if (sum & 1) return false;
        else {
            vector<bool> dp((sum >> 1) + 1, 0);
            dp[0] = true;
            for (int i = 0; i < nums.size(); i ++) // 循环顺序很重要
                for (int j = sum >> 1; j >= 1; j --) {
                    if (j >= nums[i]) dp[j] = dp[j] | dp[j - nums[i]];
                }
            return dp[sum >> 1];
        } 
    }
};