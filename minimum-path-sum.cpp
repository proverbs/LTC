/*dp*/

class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
        vector<int> v(grid[0].size(), 9999999);
        vector<vector<int> > dp;
        for (int i = 0; i < grid.size(); i ++) dp.push_back(v);
        dp[0][0] = grid[0][0];
        for (int i = 0; i < grid.size(); i ++) {
            for (int j = 0; j < grid[0].size(); j ++) {
                if (i - 1 >= 0) dp[i][j] = min(dp[i][j], dp[i - 1][j] + grid[i][j]);
                if (j - 1 >= 0) dp[i][j] = min(dp[i][j], dp[i][j - 1] + grid[i][j]);
            }
        }
        return dp[grid.size() - 1][grid[0].size() - 1];
    }
};