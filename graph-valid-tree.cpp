// DSU check tree

class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        int m = edges.size();
        if (m + 1 != n) return false;
        vector<int> fa(n);
        for (int i = 0; i < n; i ++) fa[i] = i;
        for (pair<int, int>& e: edges) {
            if (findfa(e.first, fa) != findfa(e.second, fa)) 
                fa[findfa(e.first, fa)] = findfa(e.second, fa);
            else return false;
        }
        return true;
    }
    
    int findfa(int x, vector<int>& fa) {
        if (fa[x] != x) fa[x] = findfa(fa[x], fa);
        return fa[x];
    }
};