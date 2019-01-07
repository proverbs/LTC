class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        return dfs(s, 0, t, 0, true);
    }
    
    bool dfs(string& s, int x, string& t, int y, bool r) {
        if (x == s.length() && y == t.length()) return !r;
        
        if (x == s.length() && y < t.length()) {
            if (!r) return false;
            else return dfs(s, x, t, y + 1, false); // add
        } else if (x < s.length() && y == t.length()) {
            if (!r) return false;
            else return dfs(s, x + 1, t, y, false); // delete
        } else {
            if (s[x] != t[y]) {
                if (!r) return false;
                else {
                    // replace, add, delete
                    return dfs(s, x + 1, t, y + 1, false) | dfs(s, x + 1, t, y, false) | dfs(s, x, t, y + 1, false);
                }
            } else {
                return dfs(s, x + 1, t, y + 1, r);
            }
        }
    }
};