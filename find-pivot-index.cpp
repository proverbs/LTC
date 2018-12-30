class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if (nums.size() == 0) return -1;
        vector<int> sums;
        sums.push_back(0);
        for (int i = 0; i < nums.size(); i ++) 
            sums.push_back(sums[i] + nums[i]);
        int tot = sums[nums.size()];
        for (int i = 0; i < nums.size(); i ++)
            if (sums[i] == tot - sums[i + 1]) return i;
        return -1;
    }
};