/*dfs*/
/*dp may not be simpler*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char> >& board, string word) {
        vector<vector<bool> > vis;
        vector<bool> v(board[0].size(), 0);
        for (int i = 0; i < board.size(); i ++) vis.push_back(v);
        for (int i = 0; i < board.size(); i ++) {
            for (int j = 0; j < board[0].size(); j ++) {
                if (dfs(i, j, 0, board, word, vis)) return true;
            }
        }
        return false;
    }

    bool dfs(int x, int y, int idx, vector<vector<char> >& board, string& word, vector<vector<bool> >& vis) {
        if (board[x][y] == word[idx]) {
            vis[x][y] = true;
            if (idx == word.length() - 1) return true;
            if (x - 1 >= 0 && !vis[x - 1][y] && dfs(x - 1, y, idx + 1, board, word, vis)) return true;
            if (x + 1 < board.size() && !vis[x + 1][y] && dfs(x + 1, y, idx + 1, board, word, vis)) return true;
            if (y - 1 >= 0 && !vis[x][y - 1] && dfs(x, y - 1, idx + 1, board, word, vis)) return true;
            if (y + 1 < board[0].size() && !vis[x][y + 1] && dfs(x, y + 1, idx + 1, board, word, vis)) return true;
            vis[x][y] = false;
        }
        return false;
    }
};