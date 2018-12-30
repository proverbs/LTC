// dp: 传纸条
// dp[steps][x1][x2]: how many cherries can be picked from (0, 0) to (x1, steps-x1) and from (x1, steps-x1) to (0, 0)

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        static int dx[2] = {0, -1};
        static int dy[2] = {-1, 0};
        int n = grid.size();
        vector<vector<vector<int>>> dp(2 * n - 1, vector<vector<int>>(n, vector<int>(n, -0x7f7f7f7f)));
        if (grid[0][0] == 1) dp[0][0][0] = 1;
        else if (grid[0][0] == 0) dp[0][0][0] = 0;
        for (int i = 1; i <= 2 * (n - 1); i ++)
            for (int j = 0; j < n; j ++)
                for (int k = j; k < n; k ++) {
                    int res = 0;
                    int x1 = j, y1 = i - j;
                    int x2 = k, y2 = i - k;
                    
                    if (grid[x1][y1] == 1) res ++;
                    if (grid[x2][y2] == 1) res ++;
                    if (x1 == x2) res -= grid[x2][y2] == 1;
                    
                    for (int z1 = 0; z1 < 2; z1 ++) {
                        int nx1 = x1 + dx[z1], ny1 = y1 + dy[z1];
                        if (nx1 < 0 || ny1 < 0 || grid[nx1][ny1] == -1) continue;
                        for (int z2 = 0; z2 < 2; z2 ++) {
                            int nx2 = x2 + dx[z2], ny2 = y2 + dy[z2];
                            if (nx2 < 0 || ny2 < 0 || grid[nx2][ny2] == -1) continue;
                            
                            dp[i][j][k] = max(dp[i][j][k], dp[i - 1][min(nx1, nx2)][max(nx2, nx1)] + res);
                        }
                    }
                }
        int res = dp[2 * (n - 1)][n - 1][n - 1];
        return res < 0 ? 0 : res;
    }
};