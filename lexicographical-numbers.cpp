// recursion

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        dfs(to_string(n), "", res);
        return res;
    }
    
    void dfs(const string& s, string pre, vector<int>& res) {
        int t;
        if (pre.length() < s.length()) {
            if (pre.length()) {
                sscanf(pre.c_str(), "%d", &t);
                res.push_back(t);
                dfs(s, pre + "0", res);
            }
            string z = "0";
            for (int i = 1; i <= 9; i ++) {
                z[0] = '0' + i;
                dfs(s, pre + z, res);
            }
        } else if (pre.length() == s.length()) {
            if (pre <= s) {
                sscanf(pre.c_str(), "%d", &t);
                res.push_back(t);
            }
        }
    }
};