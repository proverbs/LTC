// (1) dp[i][j]: shortest path from src to i, passing j nodes
// (2) floyd + fast power

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<int>> mp(n, vector<int>(n, 0x3f3f3f3f));
        for (int i = 0; i < flights.size(); i ++)
            mp[flights[i][0]][flights[i][1]] = flights[i][2];
        vector<vector<int>> res(n, vector<int>(n, 0x3f3f3f3f));
        for (int i = 0; i < n; i ++) res[i][i] = mp[i][i] = 0;
        K ++;
        while (K) {
            if (K & 1) res = floyd(res, mp);
            mp = floyd(mp, mp);
            K >>= 1;
        }
        return res[src][dst] == 0x3f3f3f3f ? -1 : res[src][dst];
    }
    
    vector<vector<int>> floyd(vector<vector<int>>& a, vector<vector<int>>& b) {
        int n = a.size();
        vector<vector<int>> res(n, vector<int>(n, 0x3f3f3f3f));
        for (int k = 0; k < n; k ++)
            for (int i = 0; i < n; i ++)
                for (int j = 0; j < n; j ++)
                    res[i][j] = min(res[i][j], a[i][k] + b[k][j]);
        return res;
    }
};