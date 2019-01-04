class Solution {
public:
    int tx, ty;
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        tx = destination[0];
        ty = destination[1];
        return dfs(maze, start[0], start[1]);
    }
    
    bool dfs(vector<vector<int>>& maze, int x, int y) {
        
        static int dx[4] = {0, 0, 1, -1};
        static int dy[4] = {1, -1, 0, 0};
        
        maze[x][y] = 2;
        if (x == tx && y == ty) return true;
        
        for (int i = 0; i < 4; i ++) {
            int nx = x;
            int ny = y;
            if (dx[i] != 0) {
                while (nx + dx[i] >= 0 && nx + dx[i] < maze.size() && maze[nx + dx[i]][ny] != 1) nx += dx[i];
            } else {
                while (ny + dy[i] >= 0 && ny + dy[i] < maze[0].size() && maze[nx][ny + dy[i]] != 1) ny += dy[i];
            }
            if (nx < 0 || ny < 0 || nx >= maze.size() || ny >= maze[0].size()) continue;
            if (maze[nx][ny] == 2) continue;
            if (dfs(maze, nx, ny)) return true;
        }
        return false;
    }
};