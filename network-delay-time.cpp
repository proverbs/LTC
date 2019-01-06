// spfa

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<int>> mp(N + 1, vector<int>(N + 1, 9999999));
        for (vector<int>& t : times) {
            mp[t[0]][t[1]] = t[2];
        }
        for (int i = 1; i <= N; i ++) mp[i][i] = 0;
        vector<int> dis(N + 1, 9999999);
        vector<bool> vis(N + 1, false);
        dis[K] = 0;
        vis[K] = true;
        queue<int> q;
        q.push(K);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            vis[x] = false;
            for (int i = 1; i <= N; i ++)
                if (dis[i] > dis[x] + mp[x][i]) {
                    dis[i] = dis[x] + mp[x][i];
                    if (!vis[i]) q.push(i), vis[i] = true;
                }
        }
        int res = 0;
        for (int i = 1; i <= N; i ++)
            res = max(res, dis[i]);
        return res == 9999999 ? -1 : res; 
    }
};