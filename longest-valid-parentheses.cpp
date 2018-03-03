/*dp*/
/*another solution using stack is nice*/

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> dp(s.length(), -1);
        int res = 0;
        for (int i = 0; i < s.length(); i ++) {
            dp[i] = find(s, i, dp);
            res = max(res, dp[i]);
        }
        return res;
    }

    int find(string& s, int x, vector<int>& dp) {
        if (x >= s.length()) return 0;
        if (dp[x] != -1) return dp[x];
        dp[x] = 0;
        if (s[x] == ')') return dp[x];
        else if (x + 1 < s.length()) {
            dp[x + 1] = find(s, x + 1, dp);
            if (s[x + dp[x + 1] + 1] == ')') dp[x] = dp[x + 1] + 2 + find(s, x + dp[x + 1] + 2, dp);
        }
        return dp[x];
    }
};

int main() {
    cout << Solution().longestValidParentheses(")()())") << endl;
    return 0;
}