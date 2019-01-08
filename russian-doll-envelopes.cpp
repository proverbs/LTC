// dp[i], longest increasing subsequence end with the i-th element, O(n^2) 
// dp[i], smallest ending element for the subsequence with the length of i, O(nlogn)
// a trick is [3, 4] cannot contains [3, 3], so we need to put [3, 4] before [3, 3] when sorting otherwise it will be counted as an increasing number if the order is [3, 3], [3, 4]
class Solution {
public:
    typedef pair<int, int> pr;
    
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        vector<pr>& env = envelopes;
        sort(env.begin(), env.end(), cmp);
        int n = env.size();
        if (!n) return 0;
        vector<int> dp(n, 1);
        int res = 1;
        for (int i = 1; i < n; i ++) {
            for (int j = 0; j < i && env[j].first != env[i].first; j ++)
                if (env[j].second < env[i].second) dp[i] = max(dp[i], dp[j] + 1);
            res = max(res, dp[i]);
        }
        return res;
    }
    
    static bool cmp(const pr& a, const pr& b) {
        return a.first < b.first;
    }
};