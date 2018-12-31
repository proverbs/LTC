class Solution {
public:
    int strobogrammaticInRange(string low, string high) {
        int h = dfs(high, high.length(), false);
        if (all_zero(low)) return h;
        else {
            low = sub(low);
            int l = dfs(low, low.length(), false);
            return max(0, h - l);
        }
    }
    
    int dfs(string s, int len, bool zero) {
        // cout << s << "   " << len << "  " << zero << endl;
        static int ax[4] = {1, 8, 6, 9};
        static int bx[4] = {1, 8, 9, 6};
        if (len == 1) {
            int res = 1; // 0
            res += s[0] >= '1';
            res += s[0] >= '8';
            return res;
        } else if (len == 2) {
            int res = 0;
            if (zero) res ++; // 00
            for (int i = 0; i < 4; i ++)
                if (s[0] - '0' > ax[i] || (s[0] - '0' == ax[i] && s[1] - '0' >= bx[i])) res ++;
            if (!zero) res += dfs("9", 1, false);
            return res;
        } else {
            int res = 0;
            for (int i = 0; i < 4; i ++) {
                if (s[0] - '0' == ax[i]) {
                    if (s[len - 1] - '0' >= bx[i]) res += dfs(s.substr(1, len - 2), len - 2, true);
                    else {
                        string t = s.substr(1, len - 2);
                        if (!all_zero(t)) res += dfs(sub(t), len - 2, true);
                    }
                } else if (s[0] - '0' > ax[i]) { // 11111
                    res += dfs(n_nine(len - 2), len - 2, true);
                }
            }
            if (zero) {
                if (s[0] == '0') res += dfs(s.substr(1, len - 2), len - 2, true);
                else res += dfs(n_nine(len - 2), len - 2, true);
            } else {
                res += dfs(n_nine(len - 1), len - 1, false);
            }
            return res;
        }
    }
    
    bool all_zero(string &s) {
        for (char x : s)
            if (x != '0') return false;
        return true;
    }
    
    string sub(string s) {
        int jie = 1;
        for (int i = s.length() - 1; i >= 0; i --) {
            if (s[i] - '0' >= jie) s[i] -= jie, jie = 0;
            else s[i] += 10 - jie;
        }
        return s;
    }
    
    string n_nine(int len) {
        string s;
        while (len --) s.push_back('9');
        return s;
    }
};