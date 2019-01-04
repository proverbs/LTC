class Solution {
public:
    vector<int> nxt, to, head;
    int cnt;
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        int n = pid.size();
        cnt = 0;
        nxt.resize(n, 0);
        head.clear();
        head.resize(n, -1);
        to.resize(n, 0);
        unordered_map<int, int> idx;
        for (int i = 0; i < n; i ++) idx[pid[i]] = i;
        for (int i = 0; i < n; i ++) {
            if (ppid[i]) add(idx[ppid[i]], idx[pid[i]]);
        }
        vector<int> res;
        dfs(idx[kill], res);
        for (int i = 0; i < res.size(); i ++) res[i] = pid[res[i]];
        return res;
    }
    
    void add(int u, int v) {
        to[cnt] = v;
        nxt[cnt] = head[u];
        head[u] = cnt ++;
    }
    
    void dfs(int x, vector<int>& res) {
        res.push_back(x);
        for (int i = head[x]; ~i; i = nxt[i])
            dfs(to[i], res);
    }
};