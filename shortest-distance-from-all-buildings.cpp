// bfs from all '1's

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

class Solution {
public:
    typedef pair<pair<int, int>, int> pr; // <<x, y>, d>
    vector<vector<int>> dis;
    vector<vector<int>> vis;
    int shortestDistance(vector<vector<int>>& grid) {
        dis.resize(grid.size(), vector<int>(grid[0].size(), 0));
        vis.resize(grid.size(), vector<int>(grid[0].size(), 0));
        int cnt = 0;
        for (int i = 0; i < grid.size(); i ++)
            for (int j = 0; j < grid[0].size(); j ++) {
                if (grid[i][j] == 1) {
                    cnt ++;
                    bfs(i, j, cnt, grid);
                    
                }
            }
        int res = 0x7f7f7f7f;
        for (int i = 0; i < grid.size(); i ++)
            for (int j = 0; j < grid[0].size(); j ++) 
                if (grid[i][j] == 0 && vis[i][j] == cnt) res = min(res, dis[i][j]);
        return res == 0x7f7f7f7f ? -1 : res;
    }
    
    void bfs(int x, int y, int c, vector<vector<int>>& grid) {
        queue<pr> q;
        q.push({{x, y}, 0});
        
        while (!q.empty()) {
            int ax = q.front().first.first;
            int ay = q.front().first.second;
            int d = q.front().second;
            q.pop();
            
            for (int k = 0; k < 4; k ++) {
                int nx = ax + dx[k];
                int ny = ay + dy[k];
                if (nx < 0 || nx >= grid.size()) continue;
                if (ny < 0 || ny >= grid[0].size()) continue;
                if (grid[nx][ny] == 0 && vis[nx][ny] == c - 1) {
                    vis[nx][ny] = c;
                    dis[nx][ny] += d + 1;
                    q.push({{nx, ny}, d + 1});
                }
            }
        }
    }
};