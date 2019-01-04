class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<bool> vis(n, false);
        vector<int> r;
        res.clear();
        dfs(nums, vis, r);
        return res;
    }
    
    void dfs(vector<int>& nums, vector<bool>& vis, vector<int>& r) {
        if (r.size() == nums.size()) {
            res.push_back(r);
            return;
        }
        set<int> st;
        for (int i = 0; i < nums.size(); i ++)
            if (!vis[i] && !st.count(nums[i])) {
                vis[i] = true;
                r.push_back(nums[i]);
                st.insert(nums[i]);
                dfs(nums, vis, r);
                r.pop_back();
                vis[i] = false;
            }
    }
};