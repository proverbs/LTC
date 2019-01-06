class Solution {
public:
    unordered_map<int, vector<int>> idx;
    Solution(vector<int> nums) {
        for (int i = 0; i < nums.size(); i ++) {
            int num = nums[i];
            if (idx.count(num)) idx[num].push_back(i);
            else idx[num] = vector<int>({i});
        }
    }
    
    int pick(int target) {
        vector<int>& v = idx[target];
        int sz = v.size();
        return v[rand() % sz];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */