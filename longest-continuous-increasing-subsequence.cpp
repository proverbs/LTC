class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int res = 1;
        int cur = 1;
        for (int i = 1; i < nums.size(); i ++) {
            if (nums[i] > nums[i - 1]) cur ++;
            else cur = 1;
            res = max(res, cur);
        }
        return res;
    }
};