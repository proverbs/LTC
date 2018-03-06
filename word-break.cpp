/*dp + hash map*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> mp;
        for (int i = 0; i < wordDict.size(); i ++) {
            mp[wordDict[i]] = 1;
        }
        vector<int> dp(s.length() + 1, 0);
        dp[s.length()] = 1;
        for (int i = s.length() - 1; i >= 0; i --) {
            string ts = "";
            for (int j = i; j < s.length(); j ++) {
                ts.push_back(s[j]);
                if (mp.count(ts)) dp[i] |= dp[j + 1];
            }
        }
        return dp[0];
    }
};
