class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        int x = 0, y = 0, d = 1;
        for (int i = 1; i <= n * n; i ++) {
            res[x][y] = i;
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n || res[nx][ny]) d = (d + 1) & 3;
            x += dx[d];
            y += dy[d];
        }
        return res;
    }
};