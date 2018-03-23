/*从所有临边的O开始dfs*/

class Solution {
public:
    vector<vector<int>> vis;
    static const int dx[4], dy[4];
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0) return;
        vector<int> v(board[0].size(), 0);
        vis.clear();
        for (int i = 0; i < board.size(); i ++) vis.push_back(v);
        for (int i = 0; i < board.size(); i ++) {
            if (board[i][0] == 'O' && vis[i][0] == 0) dfs(board, i, 0);
            if (board[i][board[0].size() - 1] == 'O' && vis[i][board[0].size() - 1] == 0) dfs(board, i, board[0].size() - 1);
        }
        for (int j = 0; j < board[0].size(); j ++) {
            if (board[0][j] == 'O' && vis[0][j] == 0) dfs(board, 0, j);
            if (board[board.size() - 1][j] == 'O' && vis[board.size() - 1][j] == 0) dfs(board, board.size() - 1, j);
        }
        for (int i = 0; i < board.size(); i ++) {
            for (int j = 0; j < board[0].size(); j ++) {
                if (vis[i][j] == 0 && board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }

    void dfs(vector<vector<char>>& board, int x, int y) {
        vis[x][y] = 1;
        for (int i = 0; i < 4; i ++) {
            int ax = x + dx[i];
            int ay = y + dy[i];
            if (ax >= board.size() || ax < 0 || ay >= board[0].size() || ay < 0) continue;
            if (board[ax][ay] == 'O' && vis[ax][ay] == 0) {
                dfs(board, ax, ay);
            }
        }
    }
};

const int Solution::dx[4] = {0, -1, 1, 0};
const int Solution::dy[4] = {-1, 0, 0, 1};