class Solution {
public:
    typedef pair<int, int> pr;
    int snakesAndLadders(vector<vector<int>>& board) {
        unordered_map<int, pr> mp;
        int tx, ty;
        int n = board.size();
        // fuck the board!
        int cnt = 0;
        for (int i = n - 1; i >= 0; i --) {
            if ((n - i) & 1) {
                for (int j = 0; j < n; j ++) mp[++ cnt] = {i, j};
            } else {
                for (int j = n - 1; j >= 0; j --) mp[++ cnt] = {i, j};
            }
        }
        
        vector<int> dis(n * n + 1, 9999999);
        queue<int> q;
        q.push(1);
        dis[1] = 0;
        while (!q.empty()) {
            int m = q.front();
            pr p = mp[m];
            q.pop();
            int x = p.first;
            int y = p.second;
            
            if (m == n * n) return dis[m];
            
            for (int i = 1; i <= 6; i ++) {
                int sk = m + i;
                if (sk > n * n) continue;
                
                int nx = mp[m + i].first;
                int ny = mp[m + i].second;
                if (board[nx][ny] != -1) sk = board[nx][ny];
                if (dis[sk] != 9999999) continue;
                if (dis[sk] == 9999999) {
                    dis[sk] = dis[m] + 1;
                    q.push(sk);
                } 
            }
        }
        
        return -1;
    }
};