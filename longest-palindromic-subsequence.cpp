// dp for interval implemented by dfs with cache

class Solution {
public:
    vector<vector<int>> dp;
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        if (!n) return 0;
        dp.clear();
        dp.resize(n, vector<int>(n, -1));
        return dfs(s, 0, s.length() - 1);
    }
    
    int dfs(string& s, int lt, int rt) {
        if (lt > rt) return 0;
        if (lt == rt) return 1;
        if (dp[lt][rt] >= 0) return dp[lt][rt];
        
        if (s[lt] == s[rt]) dp[lt][rt] = dfs(s, lt + 1, rt - 1) + 2;
        else dp[lt][rt] = max(dfs(s, lt + 1, rt), dfs(s, lt, rt - 1));
        
        return dp[lt][rt];
    }
};