class Solution {
public:
    vector<vector<bool>> vis;
    void solveSudoku(vector<vector<char>>& board) {
        vis.resize(27, vector<bool>(10, false)); // 9 rows, 9 cols, 9 sub-boxes
        for (int i = 0; i < 9; i ++) 
            for (int j = 0; j < 9; j ++) {
                if (board[i][j] == '.') continue;
                int x = board[i][j] - '0';
                vis[i][x] = true;
                vis[9 + j][x] = true;
                vis[18 + i / 3 * 3 + j / 3][x] = true;
            }
        
        dfs(board);
    }
    
    bool dfs(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i ++) 
            for (int j = 0; j <9; j ++)
                if (board[i][j] == '.') {
                    for (int k = 1; k <= 9; k ++) { // fill in with k
                        if (vis[i][k]) continue;
                        if (vis[9 + j][k]) continue;
                        if (vis[18 + i / 3 * 3 + j / 3][k]) continue;
                        
                        vis[i][k] = vis[9 + j][k] = true;
                        vis[18 + i / 3 * 3 + j / 3][k] = true;
                        board[i][j] = '0' + k;
                        
                        if (dfs(board)) return true;
                        
                        vis[i][k] = vis[9 + j][k] = false;
                        vis[18 + i / 3 * 3 + j / 3][k] = false;
                        board[i][j] = '.';
                    }
                    return false;
                }
        return true;
    }
};