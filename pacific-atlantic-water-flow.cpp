// bfs, o(row*col)

class Solution {
public:
    typedef pair<int, int> pr;
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        static int dx[4] = {0, 0, 1, -1};
        static int dy[4] = {1, -1, 0, 0};
        int n = matrix.size();
        if (!n) return vector<pr>();
        int m = matrix[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pr> q;
        for (int i = 0; i < m; i ++) q.push({n, i});
        for (int i = 0; i < n; i ++) q.push({i, m});
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            int h = 0;
            if (x >= 0 && x < n && y >= 0 && y < m) h = matrix[x][y];
            for (int i = 0; i < 4; i ++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (matrix[nx][ny] < h || vis[nx][ny] == 1) continue;
                vis[nx][ny] ++;
                q.push({nx, ny});
            }
        }
        
        for (int i = 0; i < m; i ++) q.push({-1, i});
        for (int i = 0; i < n; i ++) q.push({i, -1});
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            int h = 0;
            if (x >= 0 && x < n && y >= 0 && y < m) h = matrix[x][y];
            for (int i = 0; i < 4; i ++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (matrix[nx][ny] < h || vis[nx][ny] >= 2) continue;
                vis[nx][ny] += 2;
                q.push({nx, ny});
            }
        }
        
        vector<pr> res;
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < m; j ++)
                if (vis[i][j] == 3) res.push_back({i, j});
        return res;
    }
};