class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> row_max, col_max;
        for (int i = 0; i < grid.size(); i ++) {
            int mx = 0;
            for (int j = 0; j < grid[i].size(); j ++)
                mx = max(mx, grid[i][j]);
            row_max.push_back(mx);
        }
        for (int j = 0; j < grid[0].size(); j ++) {
            int mx = 0;
            for (int i = 0; i < grid.size(); i ++)
                mx = max(mx, grid[i][j]);
            col_max.push_back(mx);
        }
        int res = 0;
        for (int i = 0; i < grid.size(); i ++) 
            for (int j = 0; j < grid[i].size(); j ++)
                res += min(col_max[j], row_max[i]) - grid[i][j];
        return res;
    }
};