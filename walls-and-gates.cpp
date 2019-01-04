// typical: multi-bfs in one

class Solution {
public:
    typedef pair<int, int> pr;
    void wallsAndGates(vector<vector<int>>& rooms) {
        static int inf = 2147483647;
        static int dx[4] = {0, 0, 1, -1};
        static int dy[4] = {-1, 1, 0, 0};
        
        queue<pr> q;
        for (int i = 0; i < rooms.size(); i ++)
            for (int j = 0; j < rooms[i].size(); j ++)
                if (rooms[i][j] == 0) q.push({i, j});
        
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i ++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= rooms.size() || ny < 0 || ny >= rooms[0].size()) continue;
                if (rooms[nx][ny] == inf) {
                    rooms[nx][ny] = rooms[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
};