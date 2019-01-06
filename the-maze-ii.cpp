// O(col*row*log(row*col)), heap+dijkstra

class Solution {
public:
    typedef pair<int, int> pr; // <point, distance>
    class Compare {
    public:
        bool operator() (const pr& a, const pr& b) {
            return a.second > b.second;
        }
    };
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        static int dx[4] = {0, 0, 1, -1};
        static int dy[4] = {1, -1, 0, 0};
        
        priority_queue<pr, vector<pr>, Compare> q;
        int n = maze.size();
        int m = maze[0].size();
        q.push({start[0] * m + start[1], 0});
        vector<int> dis(n * m, 0x3f3f3f3f);
        dis[start[0] * m + start[1]] = 0;
        while (!q.empty()) {
            int z = q.top().first;
            int d = q.top().second;
            q.pop();
            if (d != dis[z]) continue;
            if (z == destination[0] * m + destination[1]) return d;
            int x = z / m;
            int y = z % m;
            for (int k = 0; k < 4; k ++) {
                int nx = x, adx = 0;
                int ny = y, ady = 0;
                if (dx[k] != 0) {
                    while (nx + dx[k] >= 0 && nx + dx[k] < n && maze[nx + dx[k]][ny] != 1) nx += dx[k], adx ++;
                } else {
                    while (ny + dy[k] >= 0 && ny + dy[k] < m && maze[nx][ny + dy[k]] != 1) ny += dy[k], ady ++;
                }
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if (dis[nx * m + ny] > d + adx + ady) {
                    dis[nx * m + ny] = d + adx + ady;
                    q.push({nx * m + ny, d + adx + ady});
                }
            }
        }
        return -1;
    }
};