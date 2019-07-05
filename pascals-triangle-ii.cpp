class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0) {
            vector<int> res(1, 1);
            return res;
        }

        vector<int> dp[2];
        dp[0].resize(rowIndex + 1, 0);
        dp[1].resize(rowIndex + 1, 0);
        dp[1][0] = dp[1][1] = 1;

        for (int i = 2; i <= rowIndex; i ++) {
            dp[i & 1][0] = dp[i & 1][i] = 1;
            for (int j = 1; j < i; j ++) 
                dp[i & 1][j] = dp[(i - 1) & 1][j - 1] + dp[(i - 1) & 1][j];
        }

        return dp[rowIndex & 1];
    }
};