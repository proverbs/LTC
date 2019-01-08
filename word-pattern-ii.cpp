class Solution {
public:
    unordered_map<char, string> mp;
    unordered_map<char, int> ct;
    bool wordPatternMatch(string pattern, string str) {
        for (char c : pattern) {
            if (ct.count(c)) ct[c] ++;
            else ct[c] = 1;
        }
        return dfs(pattern, 0, str, 0, str.length());
    }
    
    bool dfs(string& pa, int pi, string& s, int si, int rlen) {
        if (pi == pa.length()) return !rlen;
        if (mp.count(pa[pi])) {
            string& papi = mp[pa[pi]];
            if (check(s, si, papi)) return dfs(pa, pi + 1, s, si + papi.length(), rlen);
        } else {
            for (int i = 1; i * ct[pa[pi]] <= rlen; i ++) {
                string t = s.substr(si, i);
                if (check_dup(t)) continue;
                mp[pa[pi]] = t;
                if (dfs(pa, pi + 1, s, si + i, rlen - i * ct[pa[pi]])) return true;
                mp.erase(mp.find(pa[pi]));
            }
        }
        return false;
    }
    
    bool check(string& s, int si, string& t) { // an alternative is RK hash
        for (int i = 0; i < t.length(); i ++)
            if (s[si + i] != t[i]) return false;
        return true;
    }
    
    bool check_dup(string& t) {
        for (auto& pr : mp) 
            if (pr.second == t) return true;
        return false;
    }
};