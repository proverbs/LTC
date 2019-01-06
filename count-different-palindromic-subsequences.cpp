// dp

class Solution {
public:
    int mod;
    int countPalindromicSubsequences(string S) {
        if (S.length() == 0) return 0;
        mod = 1e9 + 7;
        int n = S.length();
        auto dp_ptr = new vector<vector<vector<int>>>(4, vector<vector<int>>(n, vector<int>(n)));
        auto& dp = *dp_ptr;
        for (int i = 0; i < 4; i ++)
            for (int j = 0; j < n; j ++)
                for (int k = 0; k < n; k ++)
                    dp[i][j][k] = -1;
        int res = 0;
        for (int i = 0; i < 4; i ++) {
            res += dfs(dp, S, i, 0, n - 1);
            res %= mod;
        }
        return res;
    }
    
    int dfs(auto& dp, string& s, int c, int lt, int rt) {
        if (lt > rt) return 0;
        if (~dp[c][lt][rt]) return dp[c][lt][rt];
        int& res = dp[c][lt][rt];
        if (lt == rt) return res = s[lt] == 'a' + c;
        if (s[lt] != 'a' + c && s[rt] != 'a' + c) {
            res = dfs(dp, s, c, lt + 1, rt - 1);
        } else if (s[lt] == 'a' + c && s[rt] == 'a' + c) {
            if (lt + 1 == rt) {
                res = 2; // c, cc
                return res;
            }
            
            res = 1; // cc
            res += dfs(dp, s, c, lt + 1, rt - 1);
            if (dfs(dp, s, c, lt + 1, rt - 1)) res ++; // there exists at least one c, then 1 for cc...cc or c...c...c
            else res ++; // there exists no c, then 1 for c
            res %= mod;
            for (int i = 0; i < 4; i ++) 
                if (i != c) {
                    res += dfs(dp, s, i, lt + 1, rt - 1);
                    res %= mod;
                }
        } else if (s[lt] != 'a' + c) {
            res = dfs(dp, s, c, lt + 1, rt);
        } else if (s[rt] != 'a' + c) {
            res = dfs(dp, s, c, lt, rt - 1);
        }
        return res;
    }
};