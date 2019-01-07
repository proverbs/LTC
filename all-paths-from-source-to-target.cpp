class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        res.clear();
        vector<bool> vis(graph.size(), false);
        vector<int> r;
        dfs(0, vis, r, graph);
        return res;
    }
    
    void dfs(int x, vector<bool>& vis, vector<int>& r, vector<vector<int>>& graph) {
        vis[x] = true;
        r.push_back(x);
        if (x == vis.size() - 1) {
            res.push_back(r);
        } else {
            for (int i = 0; i < graph[x].size(); i ++) {
                int to = graph[x][i];
                if (!vis[to]) dfs(to, vis, r, graph);
            }
        }
        r.pop_back();
        vis[x] = false;
    }
};