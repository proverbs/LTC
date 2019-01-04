// reverse thinking + DSU

class Solution {
public:
    vector<int> fa;
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        static int dx[4] = {-1, 0, 0, 1};
        static int dy[4] = {0, -1, 1, 0};
        int n = grid.size();
        int m = grid[0].size();
        
        for (vector<int>& a : hits) grid[a[0]][a[1]] -= 1;
        
        fa.resize(n * m + 1, 0);
        vector<int> sz(n * m + 1, 1);
        for (int i = 0; i <= n * m; i ++) fa[i] = i;
        sz[n * m] = 0;
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < m; j ++) {
                int za = i * m + j;
                if (grid[i][j] != 1) {
                    sz[za] = 0;
                    continue;
                }
                
                for (int k = 0; k < 4; k ++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx >= n || ny < 0 || ny >= m) continue;
                    int zb = -1;
                    if (nx < 0) zb = n * m;
                    else if (grid[nx][ny] == 1) zb = nx * m + ny;
                    if (zb == -1) continue;
                    
                    int ya = za, yb = zb;
                    if (findfa(ya) < findfa(yb)) swap(ya, yb);
                    // cout << ya << "-----" << yb << endl;
                    if (findfa(ya) != findfa(yb)) {
                        int t = findfa(yb);
                        fa[findfa(yb)] = findfa(ya);
                        sz[findfa(yb)] += sz[t];
                        sz[t] = 0;
                    }
                }
            }
        
        vector<int> res;
        for (int a = hits.size() - 1; a >= 0; a --) {
            int i = hits[a][0], j = hits[a][1];
            if (grid[i][j] == -1) {
                res.push_back(0);
                continue;
            }
            
            int za = i * m + j;
            grid[i][j] = 1;
            sz[za] = 1;
            fa[za] = za;
            // cout << za << endl;
            vector<int> adj;
            for (int k = 0; k < 4; k ++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx >= n || ny < 0 || ny >= m) continue;
                int zb = -1;
                if (nx < 0) zb = n * m;
                else if (grid[nx][ny] == 1) zb = nx * m + ny;
                if (zb != -1) adj.push_back(findfa(zb)); 
            }
            
            if (adj.size() == 0) {
                res.push_back(0);
                continue;
            }
            int z = -1;
            for (int b : adj) z = max(b, z);
            int num = 0;
            sz[z] += 1;
            fa[findfa(za)] = z;
            for (int b : adj) 
                if (findfa(b) != z) {
                    num += sz[findfa(b)];
                    sz[z] += sz[findfa(b)];
                    fa[findfa(b)] = z;
                }
            
            if (z == n * m) res.push_back(num);
            else res.push_back(0);
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
    
    int findfa(int x) {
        if (x != fa[x]) fa[x] = findfa(fa[x]);
        return fa[x];
    }
};