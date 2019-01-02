// dp[i][j]: max fuel when the car reaches i and has stopped at j stations for fuel
// first dimension can be compressed or even eliminated.

class Solution {
public:
    static bool cmp(const vector<int> &a, const vector<int> & b) {
        return a[0] < b[0];
    }
    
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        if (!n) return target > startFuel ? -1 : 0;
        sort(stations.begin(), stations.end(), cmp);
        
        int nn = n;
        for (int i = n - 1; i >= 0; i --)
            if (stations[i][0] > target) nn = i;
        if (!nn) return target > startFuel ? -1 : 0;
        
        if (stations[nn - 1][0] != target) stations.push_back(vector<int>({target, 0})), nn ++; // virtual station for target
        
        vector<vector<int>> dp(nn + 1, vector<int>(nn + 1, -1));
        dp[0][0] = startFuel; 
        for (int i = 1; i <= nn; i ++) {
            int dist = i - 1 > 0 ? stations[i - 1][0] - stations[i - 2][0] : stations[i - 1][0];
            for (int j = 0; j <= i; j ++) {
                if (dp[i - 1][j] >= dist) dp[i][j] = dp[i - 1][j] - dist;
                if (j > 0 && dp[i - 1][j - 1] >= dist) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] - dist + stations[i - 1][1]);
            }
        }
        
        int res = -1;
        for (int i = nn; i >= 0; i --)
            if (dp[nn][i] >= 0) res = i;
        return res;
    }
};