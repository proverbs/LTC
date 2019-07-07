// 2 dfs, the same as the diameter of tree

class Solution {
public:
    vector<int> d1, d2, d3;
    vector<int> v1;
    vector<vector<int>> mp;
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        d1.resize(n);
        d2.resize(n);
        d3.resize(n);
        v1.resize(n);
        mp.resize(n);
        for (pair<int, int>& e: edges) {
            mp[e.first].push_back(e.second);
            mp[e.second].push_back(e.first);
        }
        
        dfs1(0, -1);
        dfs2(0, -1);
        int res = n;
        for (int i = 0; i < n; i ++)
            if (res > max(d1[i], d3[i])) res = max(d1[i], d3[i]);
        vector<int> rt;
        for (int i = 0; i < n; i ++)
            if (res == max(d1[i], d3[i])) rt.push_back(i);
        cout << res << endl;
        return rt;
    }
    
    void dfs1(int x, int fa) {
        for (int y: mp[x]) if (y != fa) dfs1(y, x);
        d1[x] = 1;
        d2[x] = 1;
        v1[x] = -1;
        for (int y: mp[x]) {
            if (y == fa) continue;
            if (d1[x] <= d1[y] + 1) {
                d2[x] = d1[x];
                d1[x] = d1[y] + 1;
                v1[x] = y;
            } else {
                d2[x] = max(d2[x], d1[y] + 1);
            }
        }
    }
    
    void dfs2(int x, int fa) {
        d3[x] = 1;
        if (fa != -1) {
            if (v1[fa] != x) d3[x] = max(d3[x], d1[fa] + 1);
            else d3[x] = max(d3[x], d2[fa] + 1);
            d3[x] = max(d3[x], d3[fa] + 1);
        }
        for (int y: mp[x]) {
            if (y == fa) continue;
            dfs2(y, x);
        }
    }
};