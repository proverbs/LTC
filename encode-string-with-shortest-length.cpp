// greedy to encode from the longest duplicate substring is wrong. e.g. aaabbbaaabbbaaabbbaaa
// dp[i][j]: shortest encoded string from s[i] to s[j], O(n^3)
// typical: RK hash

class Solution {
public:
    vector<long long> ssum, pow26;
    string encode(string s) {
        int n = s.length();
        if (!n) return "";
        vector<vector<string>> dp(n, vector<string>(n));
        long long sum = 0, base = 1LL;
        ssum.clear();
        static long long mod = 1e9 + 7;
        for (char c : s) {
            sum = sum * 26 + c - 'a' + 1;
            sum %= mod;
            ssum.push_back(sum);
            pow26.push_back(base);
            base = base * 26 % mod;
        }
        return dfs(s, 0, n - 1, dp);
    }
    
    string dfs(string&s, int lt, int rt, vector<vector<string>>& dp) {
        
        string& dps = dp[lt][rt];
        if (dps.length()) return dps;
        dps = s.substr(lt, rt - lt + 1);
        if (dps.length() < 4) return dps;
        
        for (int i = lt; i < rt; i ++) {
            string t = dfs(s, lt, i, dp);
            string p = dfs(s, i + 1, rt, dp);
            if (t.length() + p.length() < dps.length()) dps = t + p;
        }
        
        for (int len = 1; len < rt - lt + 1; len ++) {
            if ((rt - lt + 1) % len) continue;
            if (check(s, lt, rt, len)) {
                string t = dfs(s, lt, lt + len - 1, dp);
                string num = to_string((rt - lt + 1) / len);
                if (t.length() + 2 + num.length() < dps.length()) dps = num + "[" + t + "]";
            }
        }
        
        return dps;
    }
    
    bool check_simple(string&s, int lt, int rt, int len) { // brute force check
        for (int i = lt + len; i <= rt; i += len) {
            for (int j = 0; j < len; j ++)
                if (s[i + j] != s[lt + j]) return false;
        }
        return true;
    }
    
    bool check(string&s, int lt, int rt, int len) { // rk hash
        static long long mod = 1e9 + 7;
        long long base = ssum[lt + len - 1];
        if (lt - 1 >= 0) base = (base + mod - ssum[lt - 1]) % mod;
        
        for (int i = lt + len; i <= rt; i += len) {
            if ((ssum[i + len - 1] - ssum[i - 1] + mod) % mod != base * pow26[i - lt] % mod) return false;
        }
        return true;
    }
};