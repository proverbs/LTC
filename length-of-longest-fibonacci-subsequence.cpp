// dp[i][j]: longest subsequence, the indexes of the last two elements are j and i.

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        int n = A.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        unordered_map<int, int> idx;
        for (int i = 0; i < n; i ++) idx[A[i]] = i + 1;
        for (int i = 1; i <= n; i ++) dp[i][0] = 1;
        
        int res = 1;
        for (int i = 1; i <= n; i ++) {
            for (int j = i - 1; j > 0; j --) {
                int dt = A[i - 1] - A[j - 1];
                if (dt < A[j - 1]) {
                    if (idx.count(dt) && dp[j][idx[dt]]) {
                        dp[i][j] = max(dp[i][j], dp[j][idx[dt]] + 1);
                    }
                } 
                if (dp[j][0]) {
                    dp[i][j] = max(dp[i][j], dp[j][0] + 1);
                }
                res = max(res, dp[i][j]);
            }
        }
        
        if (res <= 2) return 0;
        return res;
    }
};