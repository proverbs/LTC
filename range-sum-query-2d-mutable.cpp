// 2d bits

#define lowbit(x) x & -x

class NumMatrix {
public:
    vector<vector<int>> bits;
    vector<vector<int>> mx;
    bool empty;
    NumMatrix(vector<vector<int>> matrix) : mx(matrix) {
        if (matrix.size() == 0) {
            empty = true;
            return;
        }
        empty = false;
        bits.resize(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
        for (int i = 0; i < matrix.size(); i ++)
            for (int j = 0; j < matrix[0].size(); j ++)
                add(i + 1, j + 1, matrix[i][j]);
    }
    
    void update(int row, int col, int val) {
        if (empty) return;
        add(row + 1, col + 1, val - mx[row][col]);
        mx[row][col] = val;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (empty) return 0;
        int res = getsum(row2 + 1, col2 + 1) + getsum(row1, col1) - getsum(row2 + 1, col1) - getsum(row1, col2 + 1);
        return res;
    }
    
    void add(int x, int y, int val) {
        for (int i = x; i < bits.size(); i += lowbit(i))
            for (int j = y; j < bits[0].size(); j += lowbit(j))
                bits[i][j] += val;
    }
    
    int getsum(int x, int y) {
        int res = 0;
        for (int i = x; i; i -= lowbit(i))
            for (int j = y; j; j -= lowbit(j))
                res += bits[i][j];
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * obj.update(row,col,val);
 * int param_2 = obj.sumRegion(row1,col1,row2,col2);
 */