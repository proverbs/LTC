// different islands have different dfs sequences

class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));
        unordered_set<string> states;
        for (int i = 0; i < grid.size(); i ++)
            for (int j = 0; j < grid[i].size(); j ++)
                if (grid[i][j] && !vis[i][j]) {
                    string s = dfs(i, j, grid, vis);
                    if (!states.count(s)) states.insert(s);
                }
        return states.size();
    }
    
    string dfs(int x, int y, vector<vector<int>>& grid, vector<vector<bool>>& vis) {
        static int dx[4] = {0, 0, 1, -1};
        static int dy[4] = {1, -1, 0, 0};
        vis[x][y] = true;
        string res;
        for (int i = 0; i < 4; i ++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size()) continue;
            if (vis[nx][ny] || !grid[nx][ny]) continue;
            res.push_back('0' + i);
            res += dfs(nx, ny, grid, vis);
            res.push_back('0' + i + 4);
        }
        return res;
    }
};