// dp[0][i]: delete numbers less than i, and i is deleted for earning
// dp[1][i]: delete numbers less than i, and i is not deleted for earning. it should be deleted by deleting (i - 1) to guarantee no aftereffect.

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = 10001;
        vector<int> cs(n, 0);
        for (int a : nums) cs[a] ++;
        vector<int> dp[2];
        dp[0].resize(n, 0);
        dp[1].resize(n, 0);
        for (int i = 1; i < n; i ++) {
            int z = 0;
            if (i - 2 >= 0) z = max(dp[0][i - 2], dp[1][i - 2]);
            dp[0][i] = z + i * cs[i];
            dp[1][i] = dp[0][i - 1];
        }
        return max(dp[0][n - 1], dp[1][n - 1]);
    }
};