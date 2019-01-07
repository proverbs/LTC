
// O(n^3*2^n), state compressed DP
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int m = 1 << n;
        vector<vector<int>> dp(n, vector<int>(m, n * n));
        for (int i = 0; i < n; i ++)
            dp[i][1 << i] = 1;
        for (int j = 0; j < m; j ++) {
            for (int p = 0; p < n; p ++) { 
                // modify n times for dp[point][state], because dp[p1][state] can be modified by dp[p2][state]
                for (int i = 0; i < n; i ++) {
                    if (!(j & (1 << i))) continue;
                    for (int k = 0; k < graph[i].size(); k ++) {
                        int to = graph[i][k];
                        dp[to][j | (1 << to)] = min(dp[to][j | (1 << to)], dp[i][j] + 1);
                    }
                }
            }
        }
        int res = n * m;
        for (int i = 0; i < n; i ++)
            res = min(res, dp[i][m - 1]);
        return res - 1;
    }
};