// disjoint set union

class Solution {
public:
    vector<int> fa;
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> res;
        fa.clear();
        fa.resize(m * n, -1);
        vector<vector<bool>> isis(m, vector<bool>(n, false));
        int cnt = 0;
        static int dx[4] = {0, 0, 1, -1};
        static int dy[4] = {1, -1, 0, 0};
        for (pair<int, int>& pr : positions) {
            int z = pr.first * n + pr.second;
            isis[pr.first][pr.second] = true;
            fa[z] = z;
            cnt ++;
            for (int i = 0; i < 4; i ++) {
                int nx = pr.first + dx[i];
                int ny = pr.second + dy[i];
                if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                if (isis[nx][ny] && findfa(z) != findfa(nx * n + ny)) {
                    fa[findfa(z)] = findfa(nx * n + ny);
                    cnt --;
                }
            }
            res.push_back(cnt);
        }
        return res;
    }
    
    int findfa(int x) {
        if (fa[x] != x) fa[x] = findfa(fa[x]);
        return fa[x];
    }
};