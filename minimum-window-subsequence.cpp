// last character pointer
// space complexity: O(26T)
// time complexity: O(ST)

class Solution {
public:
    string minWindow(string S, string T) {
        // special judge
        if (T.length() == 0) return string("");
        
        // init the pointers
        vector<vector<int>> jp(S.length(), vector<int>(26, 0));
        vector<int> dp(26, S.length());
        
        for (int i = S.length() - 1; i >= 0; i --) {
            for (int j = 0; j < 26; j ++) {
                jp[i][j] = dp[j];
            }
            dp[S[i] - 'a'] = i;
        }
        
        // find using brute force
        int res_lt = 0, res_rt = S.length();
        for (int i = 0; i < S.length(); i ++) {
            if (T[0] != S[i]) continue;
            // special for the first jump
            int p, j;
            if (i == 0) {
                p = dp[T[0] - 'a'];
            } else {
                p = jp[i - 1][T[0] - 'a'];
            }
            for (j = 1; j < T.length() && p != S.length(); j ++) {
                p = jp[p][T[j] - 'a'];
            }
            // next jumps
            if (j == T.length() && p != S.length()) {
                // success
                if (res_rt - res_lt > p - i) {
                    res_rt = p;
                    res_lt = i;
                }
            }
        }
        
        // return
        if (res_rt == S.length()) {
            return string();
        } else {
            return S.substr(res_lt, res_rt - res_lt + 1);
        }
    }
};