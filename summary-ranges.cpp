class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if (nums.size() == 0) return res;
        int idx = 0;
        for (int i = 1; i < nums.size(); i ++) {
            if (nums[i] != nums[i - 1] + 1) {
                res.emplace_back(tostr(nums[idx], nums[i - 1]));
                idx = i;
            }
        }
        res.emplace_back(tostr(nums[idx], nums[nums.size() - 1]));
        return res;
    }
    
    string tostr(int x, int y) {
        if (x == y) return to_string(x);
        return to_string(x) + "->" + to_string(y);
    }
};