// typical: 1D solution is not applicable
// current height means the shortest piece of the bucket for the new added point

class Solution {
public:
    typedef pair<int, pair<int, int>> pr2;
    class Compare {
    public: 
        bool operator() (const pr2& a, const pr2& b) {
            return a.first > b.first;
        }
    };
    int trapRainWater(vector<vector<int>>& heightMap) {
        priority_queue<pr2, vector<pr2>, Compare> q;
        int n = heightMap.size();
        if (n <= 2) return 0;
        int m = heightMap[0].size();
        if (m <= 2) return 0;
        
        int nvis = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < m; i ++) {
            q.push({heightMap[0][i], {0, i}});
            q.push({heightMap[n - 1][i], {n - 1, i}});
            vis[0][i] = vis[n - 1][i] = true;
            nvis += 2;
        }
        for (int i = 1; i < n - 1; i ++) {
            q.push({heightMap[i][0], {i, 0}});
            q.push({heightMap[i][m - 1], {i, m - 1}});
            vis[i][0] = vis[i][m - 1] = true;
            nvis += 2;
        }
        
        int res = 0;
        int h = 0;
        static int dx[4] = {-1, 0, 0, 1};
        static int dy[4] = {0, -1, 1, 0};
        while (nvis != n * m) {
            h = max(h, q.top().first);
            int x = q.top().second.first;
            int y = q.top().second.second;
            q.pop();
            for (int k = 0; k < 4; k ++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if (vis[nx][ny]) continue;
                if (heightMap[nx][ny] < h) res += h - heightMap[nx][ny];
                q.push({heightMap[nx][ny], {nx, ny}});
                nvis ++;
                vis[nx][ny] = true;
            }
        }
        return res;
    }
};