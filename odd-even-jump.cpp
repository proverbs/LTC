// classic
// jump is always from left to right --> no aftereffects --> DP

// A trick is how to use lower_bound to find the largest value less than x

class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        int n = A.size();
        vector<int> jp[2];
        jp[0].resize(n, -1);
        jp[1].resize(n, -1);
        
        multiset<pair<int, int>> rt_min, rt_max;
        multiset<pair<int, int>>::iterator it;
        
        for (int i = 0; i < n; i ++) {
            rt_min.insert(make_pair(A[i], i));
            rt_max.insert(make_pair(-A[i], i));
        }
        
        for (int i = 0; i < n; i ++) {
            rt_min.erase(make_pair(A[i], i));
            it = rt_min.lower_bound(make_pair(A[i], 0));
            if (it != rt_min.end()) jp[1][i] = it->second;
            
            rt_max.erase(make_pair(-A[i], i));
            it = rt_max.lower_bound(make_pair(-A[i], 0));
            if (it != rt_max.end()) jp[0][i] = it->second;
        }
        
        vector<int> dp[2];
        dp[0].resize(n, 1);
        dp[1].resize(n, 0);
        
        for (int i = 0; i < n; i ++) {
            if (~jp[0][i]) dp[0][jp[0][i]] += dp[1][i];
            if (~jp[1][i]) dp[1][jp[1][i]] += dp[0][i];
        }
        
        return dp[0][n - 1] + dp[1][n - 1];
    }
};