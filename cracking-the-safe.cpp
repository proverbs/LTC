// dfs, brute force
// but it is hard to prove there must exists a result given a initial string

class Solution {
public:
    map<string, bool> mp;
    
    string crackSafe(int n, int k) {
        mp.clear();
        string st;
        int len = 1;
        for (int i = 0; i < n; i ++) {
            st.push_back(i % k + '0');
            len *= k;
        }
        mp[st] = true;
        dfs(st, k, n, len + n - 1);
        return st;
    }
    
    bool dfs(string &st, int k, int n, int len) {
        if (st.length() == len) return true;
        string s = st.substr(st.length() - n + 1);
        for (int i = 0; i < k; i ++) {
            string t;
            t.push_back(i + '0');
            if (!mp.count(s + t) || !mp[s + t]) {
                string tmp = st + t;
                mp[s + t] = true;
                if (dfs(tmp, k, n, len)) {
                    st = tmp;
                    return true;
                }
                mp[s + t] = false;
            }
        }
        return false;
    }
};