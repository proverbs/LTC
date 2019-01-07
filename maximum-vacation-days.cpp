// dp[i][j]: max vacation if staying at place i in the j-th week

class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int n = flights.size();
        int k = days[0].size();
        vector<vector<int>> dp(n, vector<int>(k, -77777));
        dp[0][0] = days[0][0];
        for (int i = 1; i < n; i ++)
            if (flights[0][i]) dp[i][0] = days[i][0];
        for (int j = 1; j < k; j ++) {
            for (int i = 0; i < n; i ++) {
                dp[i][j] = dp[i][j - 1] + days[i][j]; // stay at the same city
                for (int p = 0; p < n; p ++)
                    if (flights[p][i]) {
                        dp[i][j] = max(dp[i][j], dp[p][j - 1] + days[i][j]);
                    }
            }
        }
        int res = 0;
        for (int i = 0; i < n; i ++)
            res = max(res, dp[i][k - 1]);
        return res;
    }
};