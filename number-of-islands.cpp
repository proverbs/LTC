/*dfs*/

class Solution {
public:
    int numIslands(vector<vector<char> >& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return 0;
        vector<bool> v(grid[0].size(), 0);
        vector<vector<bool> > vis;
        for (int i = 0; i < grid.size(); i ++) vis.push_back(v);
        int res = 0;
        for (int i = 0; i < grid.size(); i ++) {
            for (int j = 0; j < grid[0].size(); j ++) {
                if (grid[i][j] == '1' && vis[i][j] == 0) {
                    dfs(i, j, vis, grid);
                    res ++;
                }
            }
        }
        return res;
    }

    void dfs(int x, int y, vector<vector<bool> >& vis, vector<vector<char> >& grid) {
        vis[x][y] = 1;
        for (int i = 0, ax, ay; i < 4; i ++) {
            ax = x + dx[i];
            ay = y + dy[i];
            if (ax >= 0 && ax < vis.size() && ay >= 0 && ay < vis[0].size() 
                && vis[ax][ay] == 0 && grid[ax][ay] == '1') {
                    dfs(ax, ay, vis, grid);
            }
        }
    }
private:
    const int dx[4] = {-1, 0, 0, 1};
    const int dy[4] = {0, 1, -1, 0};
};