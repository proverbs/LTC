// dfs, O(N*N!)

class Solution {
public:
    vector<bool> vis;
    vector<int> nums;
    int sum;
    int cnt;
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        cnt = 0;
        sum = 0;
        for (int x : nums) sum += x, this->nums.push_back(x);
        if (sum % k) return false;
        vis.resize(nums.size(), false);
        sum /= k;
        bool fg = dfs(0, k, sum);
        cout << cnt << endl;
        return fg;
    }
    
    bool dfs(int idx, int k, int sm) {
        cnt ++;
        if (!k) return true;
        for (int i = idx; i < nums.size(); i ++)
            if (!vis[i] && sm >= nums[i]) {
                vis[i] = true;
                if (sm == nums[i]) {
                    if (dfs(0, k - 1, sum)) return true;
                }
                else if (dfs(i + 1, k, sm - nums[i])) return true;
                vis[i] = false;
            }
        return false;
    }
};


// state-compressed dp, O(n*2^n)
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for (int x : nums) sum += x;
        if (sum % k) return false;
        sum /= k;
        int n = nums.size();
        vector<int> dp((1 << n), -1);
        dp[0] = 0;
        for (int i = 1; i < (1 << n); i ++) {
            for (int j = 0; j < n; j ++)
                if (i & (1 << j)) {
                    if (~dp[i - (1 << j)] && dp[i - (1 << j)] + nums[j] <= sum) 
                        dp[i] = (dp[i - (1 << j)] + nums[j]) % sum;
                }
        }
        return dp[(1 << n) - 1] == 0;
    }
};