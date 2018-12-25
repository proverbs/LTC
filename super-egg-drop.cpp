// (1) binary search only if K is large enough
// (2) dp[i][j] = min(max(dp[i - 1][k], dp[i][j - k - 1])), O(k*n^2)
// (3) dp[i][j] = 1 + dp[i - 1][j - 1] + dp[i][j - 1], 
// where dp[i][j] means given i moves and j eggs, how many floors can be excluded. O(kn)

class Solution {
public:
    int superEggDrop(int K, int N) {
        int Z = N;
        vector<vector<int>> dp(K + 1, vector<int>(Z + 1, 0));
        
        for (int i = 1; i <= K; i ++) {
            for (int j = 1; j <= Z; j ++) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1] + 1;
            }
        }
        
        for (int i = 1; i <= Z; i ++) {
            if (dp[K][i] + 1 >= N + 1) return i;
        }
    }
};