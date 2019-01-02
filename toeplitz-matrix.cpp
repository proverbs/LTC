class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); i ++)
            if (!check(i, 0, matrix)) return false;
        for (int j = 1; j < matrix[0].size(); j ++)
            if (!check(0, j, matrix)) return false;
        return true;
    }
    
    bool check(int x, int y, vector<vector<int>>& m) {
        int v = m[x][y];
        while (x < m.size() && y < m[0].size())
            if (m[x ++][y ++] != v) return false;
        return true;
    }
};