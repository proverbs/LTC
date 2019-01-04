class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size();
        if (!n) return 0;
        int m = board[0].size();
        int res = 0;
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < m; j ++)
                if (board[i][j] == 'X' && 
                    (i - 1 < 0 || board[i - 1][j] != 'X') && 
                    (j - 1 < 0 || board[i][j - 1] != 'X')) res ++; // only count the top-left X
        return res;
    }
};