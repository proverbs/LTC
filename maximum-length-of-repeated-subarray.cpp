// a awesome solution using prefix hash: 
// https://leetcode.com/problems/maximum-length-of-repeated-subarray/discuss/156891/Binary-Search-%2B-Rabin-Karp-%2B-Hash-Table-O(N-log-N)-Beats-100

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int na = A.size(), nb = B.size();
        vector<vector<int>> dp(na, vector<int>(nb, 0));
        int res = 0;
        for (int i = 0; i < na; i ++)
            for (int j = 0; j < nb; j ++)
                if (A[i] == B[j]) {
                    int z = 0;
                    if (i - 1 >= 0 && j - 1 >= 0) z = dp[i - 1][j - 1];
                    dp[i][j] = z + 1;
                    res = max(res, dp[i][j]);
                }
        
        return res;
    }
};