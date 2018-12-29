// bfs, O(6!*4*6)
// a better way is bfs from source and target at the same time

class Solution {
public:
    typedef pair<int, int> pr; // <state, #moves>
    static int dx[4], dy[4];
    int slidingPuzzle(vector<vector<int>>& board) {
        vector<bool> vis(600000, false);
        int target = 123450;
        queue<pr> q;
        int s = state2num(board);
        q.push({s, 0});
        vis[s] = true;
        while (!q.empty()) {
            int state = q.front().first;
            int moves = q.front().second;
            q.pop();
            if (state == target) return moves;
            num2state(state, board);
            int x, y;
            getxy(x, y, board);
            for (int i = 0; i < 4; i ++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= 2 || ny < 0 || ny >= 3) continue;
                swap(board[x][y], board[nx][ny]);
                int nstate = state2num(board);
                if (!vis[nstate]) q.push({nstate, moves + 1}), vis[nstate] = true;
                swap(board[x][y], board[nx][ny]);
            }
        }
        
        return -1;
    }
    
    void num2state(int state, vector<vector<int>> &bd) {
        for (int i = 1; i >= 0; i --)
            for (int j = 2; j >= 0; j --)
                bd[i][j] = state % 10, state /= 10;
    }
    
    int state2num(vector<vector<int>> &bd) {
        int res = 0;
        for (int i = 0; i < 2; i ++)
            for (int j = 0; j < 3; j ++)
                res = res * 10 + bd[i][j];
        return res;
    }
    
    void getxy(int &x, int &y, vector<vector<int>> &bd) {
        for (int i = 0; i < 2; i ++)
            for (int j = 0; j < 3; j ++)
                if (bd[i][j] == 0) {
                    x = i, y = j;
                    return;
                }
    }
};

int Solution::dx[4] = {0, 0, -1, 1};
int Solution::dy[4] = {-1, 1, 0, 0};