class Solution {
public:
    vector<vector<int>> mk;
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        mk.resize(board.size(), vector<int>(board[0].size(), 0));
        crush(board);
        return board;
    }
    
    void crush(vector<vector<int>> &bd) {
        for (int i = 0; i < mk.size(); i ++)
            for (int j = 0; j < mk[0].size(); j ++)
                mk[i][j] = 0;
        
        for (int i = 0; i < mk.size(); i ++)
            for (int j = 0; j < mk[0].size(); j ++)
                if (bd[i][j]) mark(i, j, bd);
        
        if (drop(bd)) crush(bd);
    }
    
    void mark(int x, int y, vector<vector<int>> &bd) {
        if (mk[x][y] != 1) {
            // vertical
            int nx = x;
            while (nx + 1 < bd.size() && bd[nx + 1][y] == bd[x][y]) nx ++;
            if (nx - x + 1 >= 3) 
                 for (int i = x; i <= nx; i ++) mk[i][y] = 1;
        }
        if (mk[x][y] != 2) {
            // horizontal
            int ny = y;
            while (ny + 1 < bd[0].size() && bd[x][ny + 1] == bd[x][y]) ny ++;
            if (ny - y + 1 >= 3) 
                for (int i = y; i <= ny; i ++) mk[x][i] = 2;
        }
    }
    
    bool drop(vector<vector<int>> &bd) {
        bool fg = false;
        for (int j = 0; j < mk[0].size(); j ++) {
            for (int i = 0; i < mk.size(); i ++)
                if (mk[i][j] > 0) bd[i][j] = 0, fg = true;
            int i = mk.size() - 1, k = i;
            for (;i >= 0; i --) 
                if (bd[i][j] != 0) bd[k --][j] = bd[i][j];
            while (k >= 0) bd[k --][j] = 0;
        }
        
        
        return fg;
    }
};