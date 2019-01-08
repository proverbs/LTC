// state compressed dikstra(optimized by PQ)

class Solution {
public:
    struct State {
        int x, y;
        int key;
        int d;
    };
    class Compare {
    public:
        bool operator() (const State& a, const State& b) {
            return a.d > b.d;
        }
    };
    int shortestPathAllKeys(vector<string>& grid) {
        static int dx[4] = {-1, 0, 0, 1};
        static int dy[4] = {0, -1, 1, 0};
        
        int n = grid.size();
        int m = grid[0].size();
        int sx, sy, sk = 0;
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < m; j ++) {
                if (grid[i][j] == '@') sx = i, sy = j;
                else if (grid[i][j] >= 'a' && grid[i][j] <= 'f') sk ++;
            }
        
        int dk = 1 << sk;
        vector<vector<int>> dp(n * m, vector<int>(dk, 9999999));
        dp[sx * m + sy][0] = 0;
        priority_queue<State, vector<State>, Compare> pq;
        pq.push({sx, sy, 0, 0});
        while (!pq.empty()) {
            int x = pq.top().x;
            int y = pq.top().y;
            int key = pq.top().key;
            int d = pq.top().d;
            pq.pop();
            if (d > dp[x * m + y][key]) continue;
            if (key == dk - 1) return d;
            for (int k = 0; k < 4; k ++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if (grid[nx][ny] == '#') continue;
                int nkey = key;
                if (grid[nx][ny] >= 'A' && grid[nx][ny] <= 'F' && !(key & (1 << (grid[nx][ny] - 'A')))) continue;
                if (grid[nx][ny] >= 'a' && grid[nx][ny] <= 'f') nkey |= 1 << (grid[nx][ny] - 'a');
                if (d + 1 < dp[nx * m + ny][nkey]) {
                    dp[nx * m + ny][nkey] = d + 1;
                    pq.push({nx, ny, nkey, d + 1});
                }
            }
        }
        return -1;
    }
};