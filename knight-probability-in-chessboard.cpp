class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        static int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
        static int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
        vector<vector<vector<double>>> cs(K + 1, vector<vector<double>>(N, vector<double>(N, 0)));
        cs[0][r][c] = 1.0;
        for (int i = 0; i < K; i ++) {
            for (int x = 0; x < N; x ++)
                for (int y = 0; y < N; y ++)
                    if (cs[i][x][y]) {
                        for (int k = 0; k < 8; k ++) {
                            int nx = x + dx[k];
                            int ny = y + dy[k];
                            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                            cs[i + 1][nx][ny] += 1.0 * cs[i][x][y] / 8;
                        }
                    }
        }
        
        double res = 0.0;
        for (int x = 0; x < N; x ++) 
            for (int y = 0; y < N; y ++) 
                res += cs[K][x][y];
        return res;
    }
};