// 2d prefix sum

class NumMatrix {
public:
    vector<vector<int>> sum2d;
    NumMatrix(vector<vector<int>> matrix) {
        if (matrix.size() == 0) return;
        sum2d.resize(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
        for (int i = 0; i < matrix.size(); i ++) 
            for (int j = 0; j < matrix[0].size(); j ++)
                sum2d[i + 1][j + 1] = sum2d[i][j + 1] + sum2d[i + 1][j] - sum2d[i][j] + matrix[i][j];
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum2d[row2 + 1][col2 + 1] - sum2d[row1][col2 + 1] - sum2d[row2 + 1][col1] + sum2d[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */