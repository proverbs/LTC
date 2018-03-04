/*dp*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        word1 = "#" + word1;
        word2 = "#" + word2; // avoid empty string
        vector<vector<int> > dp;
        vector<int> v(word2.length() + 1, 99999999);
        for (int i = 0; i <= word1.length(); i ++) dp.push_back(v);
        dp[0][0] = 0;
        for (int i = 1; i <= word1.length(); i ++) {
            for (int j = 1; j <= word2.length(); j ++) {
                if (word1[i - 1] == word2[j - 1]) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1); // replace
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1); // delete
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1); // insert
            }
        }
        return dp[word1.length()][word2.length()];
    }
};