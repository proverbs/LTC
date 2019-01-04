class Solution {
public:
    vector<int> to, nxt, head;
    int cnt;
    vector<int> s, n, p, fa;
    int N;
    
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        this->N = N;
        head.clear();
        head.resize(N, -1);
        to.resize(N + N, 0);
        nxt.resize(N + N, 0);
        cnt = 0;
        s.resize(N, 0);
        n.resize(N, 0);
        fa.clear();
        fa.resize(N, -1);
        p.resize(N, 0);
        
        for (vector<int>& e : edges) {
            add(e[0], e[1]);
            add(e[1], e[0]);
        }
        
        dfs_sn(0);
        dfs_p(0);
        vector<int> dis;
        for (int i = 0; i < N; i ++)
            dis.push_back(s[i] + p[i]);
        
        return dis;
    }
    
    void add(int u, int v) {
        to[cnt] = v;
        nxt[cnt] = head[u];
        head[u] = cnt ++;
    }
    
    void dfs_sn(int x) { // distance from its children
        n[x] = 1;
        s[x] = 0;
        for (int i = head[x]; ~i; i = nxt[i])
            if (to[i] != fa[x]) {
                fa[to[i]] = x;
                dfs_sn(to[i]);
                n[x] += n[to[i]];
                s[x] += s[to[i]] + n[to[i]];
            }
    }
    
    void dfs_p(int x) { // distance from its father
        if (fa[x] == -1) p[x] = 0;
        else {
            p[x] = s[fa[x]] - (s[x] + n[x]);
            p[x] += n[fa[x]] - n[x];
            p[x] += p[fa[x]] + (N - n[fa[x]]);
        }
        for (int i = head[x]; ~i; i = nxt[i])
            if (to[i] != fa[x]) 
                dfs_p(to[i]);
    }
};