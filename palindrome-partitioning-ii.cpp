// O(n^2) Time, O(n) Space: dp + RK hash
// O(n^2) Time, O(n^2) Space: pre-process is_palindrome[i][j]

class Solution {
public:
    #define mod 1000000007
    int minCut(string s) {
        int n = s.length();
        if (!n) return 0;
        
        vector<long long> base(n);
        base[0] = 1LL;
        for (int i = 1; i < n; i ++) 
            base[i] = base[i - 1] * 26 % mod;
        vector<long long> hash1(n), hash2(n);
        hash1[0] = s[0] - 'a' + 1;
        for (int i = 1; i < n; i ++) 
            hash1[i] = (hash1[i - 1] + base[i] * (s[i] - 'a' + 1) % mod) % mod;
        
        hash2[n - 1] = s[n - 1] - 'a' + 1;
        for (int i = n - 2; i >= 0; i --)
            hash2[i] = (hash2[i + 1] + (s[i] - 'a' + 1) * base[n - 1 - i] % mod) % mod;
        
        // dp
        vector<int> dp(n, n);
        for (int i = 0; i < n; i ++) {
            if (check(0, i, hash1, hash2, base)) dp[i] = 1;
            else {
                for (int j = i; j >= 1; j --)
                    if (check(j, i, hash1, hash2, base))
                        dp[i] = min(dp[i], dp[j - 1] + 1);
            }
        }
        
        return dp[n - 1] - 1;
    }
    
    bool check(int lt, int rt, vector<long long>& h1, vector<long long>& h2, vector<long long>& base) {
        int n = h1.size();
        long long t = h1[rt];
        if (lt != 0) t = (t + mod - h1[lt - 1]) % mod;
        long long p = h2[lt];
        if (rt != n - 1) p = (p + mod - h2[rt + 1]) % mod;
        int bt = lt, bp = n - 1 - rt;
        if (bt < bp) t = t * base[bp - bt] % mod;
        else if (bt > bp) p = p * base[bt - bp] % mod;
        return t == p;
    }
};