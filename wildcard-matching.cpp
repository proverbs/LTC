/*dp*/

class Solution {
public:
    bool isMatch(string s, string p) {
        s = "#" + s;
        p = "#" + p;
        // 避免空串
        vector<bool> v(p.length(), 0);
        vector<vector<bool> > dp;
        for (int i = 0; i < s.size(); i ++) dp.push_back(v);
        dp[0][0] = true;
        for (int i = 0; i < s.length(); i ++) {
            for (int j = 0; j < p.length(); j ++) {
                if (p[j] == '*') {
                    if (i - 1 >= 0) dp[i][j] = dp[i][j] | dp[i - 1][j];
                    if (j - 1 >= 0) dp[i][j] = dp[i][j] | dp[i][j - 1];
                    if (i == 0 && j == 0) dp[i][j] = true;
                }
                else if (p[j] == '?' || p[j] == s[i]) {
                    if (i - 1>= 0 && j - 1 >= 0) dp[i][j] = dp[i][j] | dp[i - 1][j - 1];
                    if (i == 0 && j== 0) dp[i][j] = true;
                }
            }
        }
        return dp[s.length() - 1][p.length() - 1];
    }
};