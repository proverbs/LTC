
// O(n^2) dp
class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, int> idx;
        int n = stones.size();
        for (int i = 0; i < n; i ++) idx[stones[i]] = i;
        
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        dp[0][0] = true;
        for (int i = 0; i < n - 1; i ++) {
            for (int j = 0; j < n - 1; j ++) {
                if (!dp[i][j]) continue;
                int x = stones[i] + j;
                
                if (j - 1 > 0 && idx.count(x - 1)) dp[idx[x - 1]][j - 1] = true;
                if (j > 0 && idx.count(x)) dp[idx[x]][j] = true;
                if (idx.count(x + 1)) dp[idx[x + 1]][j + 1] = true;
            }
        }
        
        for (int i = 1; i < n; i ++) 
            if (dp[n - 1][i]) return true;
        return false;
    }
};