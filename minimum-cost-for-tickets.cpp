// classic: dp

// O(365), or O(400).
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_map<int, bool> mp;
        for (int day: days) mp[day] = true;
        
        vector<int> dp(401, 9999999);
        dp[0] = 0;
        
        for (int i = 1; i <= 400; i ++) {
            if (!mp[i]) dp[i] = dp[i - 1];
            dp[i] = min(dp[i], dp[i - 1] + costs[0]);
            if (i >= 7) dp[i] = min(dp[i], dp[i - 7] + costs[1]);
            if (i >= 30) dp[i] = min(dp[i], dp[i - 30] + costs[2]);
        }
        
        return dp[400];
    }
};

// O(n).
// dp[i]: minimal cost from days[i] to the last day.
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        if (!n) return 0;
        vector<int> dp(n + 1, 9999999);
        dp[n] = 0;
        days.push_back(days[n - 1] + 1);
        
        int n1 = n - 1, n7 = n - 1, n30 = n - 1;
        for (int i = n - 1; i >= 0; i --) {
            while (days[n1] >= days[i] + 1) n1 --;
            while (days[n7] >= days[i] + 7) n7 --;
            while (days[n30] >= days[i] + 30) n30 --;
            
            dp[i] = min(dp[i], dp[n1 + 1] + costs[0]);
            dp[i] = min(dp[i], dp[n7 + 1] + costs[1]);
            dp[i] = min(dp[i], dp[n30 + 1] + costs[2]);
        }
        
        return dp[0];
    }
};