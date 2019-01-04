// dfs with cache to implement dp

class Solution {
public:
    vector<vector<int>> dp;
    bool checkValidString(string s) {
        int n = s.length();
        if (!n) return true;
        dp.resize(n, vector<int>(n, -1));
        return dfs(s, 0, n - 1);
    }
    
    int dfs(string& s, int lt, int rt) {
        if (lt > rt) return 1;
        if (dp[lt][rt] != -1) return dp[lt][rt];
        if (lt == rt && s[lt] == '*') return dp[lt][rt] = 1;
        dp[lt][rt] = 0;
        for (int mid = lt + 1; mid <= rt; mid ++)
            if ((s[lt] == '(' || s[lt] == '*') && (s[mid] == ')' || s[mid] == '*'))
                dp[lt][rt] |= dfs(s, lt + 1, mid - 1) & dfs(s, mid + 1, rt);
        return dp[lt][rt];
    }
};