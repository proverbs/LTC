// same as 2sum by using prefix sums

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> smap;
        vector<int> sums(nums.size() + 1, 0);
        for (int i = 1; i <= nums.size(); i ++) 
            sums[i] = sums[i - 1] + nums[i - 1];
        int res = 0;
        smap[0] = 0;
        for (int i = 1; i <= nums.size(); i ++) {
            if (smap.count(sums[i] - k)) res = max(res, i - smap[sums[i] - k]);
            if (!smap.count(sums[i])) smap[sums[i]] = i;
        }
        return res;
    }
};