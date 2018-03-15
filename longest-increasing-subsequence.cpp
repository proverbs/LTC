/*dp, Longest Increasing Subsequence*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector<int> s(nums.size() + 1, 99999999);
        s[0] = -99999999;
        int res = 1;
        for (int i = 0; i < nums.size(); i ++) {
            int lt = 0, rt = i, ans;
            while (lt <= rt) {
                int mid = lt + rt >> 1;
                if (s[mid] < nums[i]) ans = mid, lt = mid + 1;
                else rt = mid - 1;
            }
            if (nums[i] < s[ans + 1]) s[ans + 1] = nums[i];
            res = max(res, ans + 1);
        }
        return res;
    }
};