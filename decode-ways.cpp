/*dp*/

class Solution {
public:
    int numDecodings(string s) {
        if (s.length() == 0) return 0;
        vector<int> dp(s.length() + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < s.length(); i ++) {
            if (isNum(s, i, i)) dp[i + 1] += dp[i + 1- 1];
            if (i - 1 >= 0 && isNum(s, i - 1, i)) dp[i + 1] += dp[i + 1- 2];
        }
        return dp[s.length()];
    }

    bool isNum(string& s, int lt, int rt) {
        if (lt == rt) return s[lt] != '0';
        else return s[lt] == '1' || (s[lt] == '2' && s[rt] >= '0' && s[rt] <= '6');
    }
};