// dp with saving path(decision)

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<vector<int>> dp(nums.size(), vector<int>(4, 0));
        vector<vector<int>> prev(nums.size(), vector<int>(4, -1));
        vector<int> sum(nums.size() + 1, 0);
        sum[0] = 0;
        for (int i = 1; i <= nums.size(); i ++) sum[i] = nums[i - 1] + sum[i - 1];
        
        for (int i = 0; i < nums.size(); i ++)
            for (int j = 1; j <= 3; j ++) {
                if (i - 1 >= 0 && dp[i][j] <= dp[i - 1][j]) dp[i][j] = dp[i - 1][j], prev[i][j] = 0;
                if (i - k >= 0 && dp[i][j] < dp[i - k][j - 1] + sum[i + 1] - sum[i - k + 1]) 
                    dp[i][j] = dp[i - k][j - 1] + sum[i + 1] - sum[i - k + 1], prev[i][j] = 1;
                if (i - k == -1 && j == 1 && dp[i][j] < sum[i + 1] - sum[i - k + 1]) dp[i][j] = sum[i + 1] - sum[i - k + 1], prev[i][j] = 1;
            }
        vector<int> res;
        int x = nums.size() - 1, cnt = 3;
        while (x != -1 && cnt) {
            if (prev[x][cnt] == 0) x --;
            else res.push_back(x - k + 1), x -= k, cnt --;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};