/*区间dp，逆向思维*/
/*tipical*/

class Solution {
public:
    vector<int> sn;
    int maxCoins(vector<int>& nums) {
        sn.clear();
        sn.push_back(1);
        for (int i = 0; i < nums.size(); i ++) sn.push_back(nums[i]);
        sn.push_back(1);
        vector<int> v(501, -99999999);
        vector<vector<int> > dp;
        for (int i = 0; i <= 500; i ++) dp.push_back(v);
        vector<bool> z(501, false);
        vector<vector<bool> > vis;
        for (int i = 0; i <= 500; i ++) vis.push_back(z);
        return dfs(1, nums.size(), dp, vis);
    }

    int dfs(int lt, int rt, vector<vector<int> >& dp, vector<vector<bool> >& vis) {
        if (rt < lt) return 0;
        if (vis[lt][rt]) return dp[lt][rt];
        // 此处i枚举的是最后被消除的数字
        for (int i = lt; i <= rt; i ++) {
            dp[lt][rt] = max(dp[lt][rt], dfs(lt, i - 1, dp, vis) + dfs(i + 1, rt, dp, vis) + sn[lt - 1] * sn[i] *sn[rt + 1]);
        }
        vis[lt][rt] = true;
        return dp[lt][rt];
    }
};