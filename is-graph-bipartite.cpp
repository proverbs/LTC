// dfs coloring
// O(n)

class Solution {
public:
    int n;
    vector<int> vis;
    bool isBipartite(vector<vector<int>>& graph) {
        n = graph.size();
        vis.resize(n, 0);
        for (int i = 0; i < n; i ++) {
            if (vis[i] == 0 && !dfs(i, 1, graph)) return false;
        }
        return true;
    }
    
    bool dfs(int x, int color, vector<vector<int>>& graph) {
        vis[x] = color;
        for (int i = 0; i < graph[x].size(); i ++) {
            int  y = graph[x][i];
            if (vis[y] == vis[x]) return false;
            else if (vis[y] == 0 && !dfs(y, color * -1, graph)) return false;
        }
        return true;
    }
};