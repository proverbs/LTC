// one pass O(row*col)

class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        static int dx[4] = {0, 1, 1, 1};
        static int dy[4] = {1, 0, 1, -1};
        int res = 0;
        int n = M.size();
        if (!n) return 0;
        int m = M[0].size();
        
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < m; j ++) {
                if (!M[i][j]) continue;
                for (int k = 0; k < 4; k ++) {
                    int zx = i - dx[k], zy = j - dy[k];
                    if (zx < 0 || zy < 0 || zx >= n || zy >= m || M[zx][zy] != 1) {
                        int len = 0;
                        int x = i, y = j;
                        while (x >= 0 && y >= 0 && x < n && y < m && M[x][y] == 1)
                            x += dx[k], y += dy[k], len ++;
                        res = max(res, len);
                    } 
                }
                
            }
        return res;
    }
};