// O(n) for each move()

class TicTacToe {
public:
    
    vector<int> win[2];
    int n;
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        win[0].resize(n + n + 2, 0); // n + n + 2 ways to win
        win[1].resize(n + n + 2, 0);
        this->n = n;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        int p = player - 1;
        int res = 0;
        res = max(++ win[p][row], res);
        res = max(++ win[p][n + col], res);
        if (row == col) res = max(++ win[p][n + n], res);
        if (row + col == n - 1) res = max(++ win[p][n + n + 1], res);
        if (res == n) return player;
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */