// DSU

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> fa(n + 1);
        for (int i = 1; i <= n; i ++) fa[i] = i;
        for (vector<int>& e: edges) {
            if (findfa(e[0], fa) != findfa(e[1], fa)) fa[findfa(e[0], fa)] = findfa(e[1], fa);
            else return e;
        }
        return edges[0]; // dummy
    }
    
    int findfa(int x, vector<int>& fa) {
        if (fa[x] != x) fa[x] = findfa(fa[x], fa);
        return fa[x];
    }
};