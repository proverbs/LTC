// similar to longest common subsequence
// dp[i][j]: first i letters in s3 matching first j letters in s1 and first (i - j) letters in s2

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.length() != s1.length() + s2.length()) return false;
        vector<vector<bool>> dp(s3.length() + 1, vector<bool>(s1.length() + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= s3.length(); i ++)
            for (int j = 0; j <= min(i, (int)s1.length()); j ++) {
                if (j - 1 >= 0 && s1[j - 1] == s3[i - 1]) dp[i][j] = dp[i][j] | dp[i - 1][j - 1];
                if (i - j <= s2.length() && s2[i - j - 1] == s3[i - 1]) dp[i][j] = dp[i][j] | dp[i - 1][j];
            }
        return dp[s3.length()][s1.length()];
    }
};