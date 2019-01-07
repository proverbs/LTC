class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        vector<vector<int>> res(A);
        int n = A.size();
        int m = A[0].size();
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < m; j ++)
                res[i][j] = !A[i][m - 1 - j];
        return res;
    }
};