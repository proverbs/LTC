// dp[i][j]: number of ways to play first i songs using j unique songs 

class Solution {
public:
    int numMusicPlaylists(int N, int L, int K) {
        static long long mod = 1e9 + 7;
        vector<vector<long long>> dp(L + 1, vector<long long>(N + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= L; i ++)
            for (int j = 1; j <= N; j ++) {
                dp[i][j] = dp[i - 1][j - 1] * (N - (j - 1)); // play a new song
                if (j - K > 0) dp[i][j] += dp[i - 1][j] * (j - K); // play an old song
                dp[i][j] %= mod;
            }
        return dp[L][N];
    }
};