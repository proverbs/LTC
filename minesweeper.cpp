// dfs

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        reveal(board, click[0], click[1]);
        return board;
    }
    
    void reveal(vector<vector<char>>& board, int x, int y) {
        if (board[x][y] == 'M') {
            board[x][y] = 'X';
            return;
        } else {
            int cnt_mine = 0;
            for (int i = -1; i <= 1; i ++)
                for (int j = -1; j <= 1; j ++) {
                    if (i == 0 && j == 0) continue;
                    if (x + i < 0 || x + i >= board.size()) continue;
                    if (y + j < 0 || y + j >= board[0].size()) continue;
                    if (board[x + i][y + j] == 'M') cnt_mine ++;
                }
            if (cnt_mine == 0) {
                board[x][y] = 'B';
                for (int i = -1; i <= 1; i ++)
                    for (int j = -1; j <= 1; j ++) {
                        if (i == 0 && j == 0) continue;
                        if (x + i < 0 || x + i >= board.size()) continue;
                        if (y + j < 0 || y + j >= board[0].size()) continue;
                        if (board[x + i][y + j] == 'E') reveal(board, x + i, y + j);
                    }
            } else {
                board[x][y] = '0' + cnt_mine;
            }
        }
    }
};