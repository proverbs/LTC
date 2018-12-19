class Solution {
public:
    vector<vector<bool>> vis;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vis.resize(grid.size(), vector<bool>(grid[0].size(), false));
        int res = 0;
        for (int i = 0; i < grid.size(); i ++) {
            for (int j = 0; j < grid[0].size(); j ++) {
                if (grid[i][j] && !vis[i][j]) {
                    res = max(res, dfs(i, j, grid));
                }
            }
        }
        return res;
    }
    
    int dfs(int x, int y, vector<vector<int>>& grid) {
        int res = 1;
        vis[x][y] = true;
        for (int i = 0; i < 4; i ++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < grid.size() && 
                ny >= 0 && ny < grid[0].size() && 
                grid[nx][ny] && !vis[nx][ny]) {
                res += dfs(nx, ny, grid);
            }
        }
        return res;
    }
};