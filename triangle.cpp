// dp, space compressed

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(2, vector<int>(n, 0x3f3f3f3f));
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < n; i ++) 
            for (int j = 0; j <= i; j ++) {
                int min_val = 0x3f3f3f3f;
                if (j != i) min_val = min(min_val, dp[(i - 1) & 1][j] + triangle[i][j]);
                if (j) min_val = min(min_val, dp[(i - 1) & 1][j - 1] + triangle[i][j]);
                dp[i & 1][j] = min_val;
            }
        int res = 0x3f3f3f3f;
        for (int i = 0; i < n; i ++)
            res = min(res, dp[(n - 1) & 1][i]);
        return res;
    }
};