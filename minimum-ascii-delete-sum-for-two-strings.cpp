class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 9999999));
        dp[0][0] = 0;
        for (int i = 0; i <= n1; i ++)
            for (int j = 0; j <= n2; j ++) {
                if (i >= 1 && j >= 1 && s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                if (i >= 1) dp[i][j] = min(dp[i][j], dp[i - 1][j] + s1[i - 1]);
                if (j >= 1) dp[i][j] = min(dp[i][j], dp[i][j - 1] + s2[j - 1]);
            }
        return dp[n1][n2];
    }
};