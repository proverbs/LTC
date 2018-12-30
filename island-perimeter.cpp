class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;
        static int dx[4] = {-1, 1, 0, 0};
        static int dy[4] = {0, 0, 1, -1};
        int res = 0;
        for (int i = 0; i < grid.size(); i ++)
            for (int j = 0; j < grid[0].size(); j ++) {
                if (!grid[i][j]) continue;
                for (int k = 0; k < 4; k ++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size()) res ++;
                    else if (!grid[nx][ny]) res ++;
                }
            }
        return res;
    }
};