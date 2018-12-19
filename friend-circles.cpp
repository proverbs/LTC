
class Solution {
public:
    vector<bool> vis;
    int findCircleNum(vector<vector<int>>& M) {
        vis.resize(M.size(), false);
        int res = 0;
        for (int i = 0; i < M.size(); i ++) {
            if (!vis[i]) {
                res ++;
                dfs(i, M);
            }
        }
        return res;
    }
    
    void dfs(int x, vector<vector<int>>& M) {
        vis[x] = true;
        for (int i = 0; i < M.size(); i ++) {
            if (M[x][i] && !vis[i]) {
                dfs(i, M);
            }
        }
    }
};