class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.size() == 0) return res;
        dfs(0, 0, 0, matrix, res);
        return res;
    }
    
    void dfs(int x, int y, bool d, vector<vector<int>>& m, vector<int>& res) {
        // cout << x << " " << y << endl;
        res.push_back(m[x][y]);
        if (x == m.size() - 1 && y == m[0].size() - 1) return;
        if (d == 0) {
            int nx = x - 1, ny = y + 1;
            if (ny >= m[0].size()) nx = x + 1, ny = y, d = !d;
            else if (nx < 0) nx = x, ny = y + 1, d = !d;
            dfs(nx, ny, d, m, res);
        } else {
            int nx = x + 1, ny = y - 1;
            if (nx >= m.size()) nx = x, ny = y + 1, d = !d;
            else if (ny < 0) nx = x + 1, ny = y, d = !d;
            dfs(nx, ny, d, m, res);
        }
    }
};