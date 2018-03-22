/*暴力*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char> >& board) {
        bool c[10];
        // row
        for (int i = 0; i < 9; i ++) {
            clear(c);
            for (int j = 0; j < 9; j ++) {
                if (board[i][j] != '.') {
                    if (c[board[i][j] - '0']) return false;
                    c[board[i][j] - '0'] = true;
                }
            }
        }
        // column
        for (int i = 0; i < 9; i ++) {
            clear(c);
            for (int j = 0; j < 9; j ++) {
                if (board[j][i] != '.') {
                    if (c[board[j][i] - '0']) return false;
                    c[board[j][i] - '0'] = true;
                }
            }
        }
        // sub box
        for (int x = 0; x < 3; x ++) {
            for (int y = 0; y < 3; y ++) {
                clear(c);
                for (int i = 0; i < 3; i ++) {
                    for (int j = 0; j < 3; j ++) {
                        int a = 3 * x + i;
                        int b = 3 * y + j;
                        if (board[a][b] != '.') {
                            if (c[board[a][b] - '0']) return false;
                            c[board[a][b] - '0'] = true;
                        }
                    }
                }
            }
        }
        return true;
    }

    void clear(bool *c) {
        for (int i = 0; i < 10; i ++) {
            c[i] = 0;
        }
    }
};