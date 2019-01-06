class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        vector<vector<bool>> mp(n, vector<bool>(n, false));
        for (pair<int, int>& e : edges) {
            mp[e.first][e.second] = mp[e.second][e.first] = true;
        }
        vector<bool> vis(n, false);
        int res = 0;
        for (int i = 0; i < n; i ++)
            if (!vis[i]) dfs(i, mp, vis), res ++;
        return res;
    }
    
    void dfs(int x, vector<vector<bool>>& mp, vector<bool>& vis) {
        vis[x] = true;
        for (int i = 0; i < mp.size(); i ++)
            if (!vis[i] && mp[x][i]) dfs(i, mp, vis);
    }
};