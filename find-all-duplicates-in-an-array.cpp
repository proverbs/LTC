//typical: swap number at position i to position (nums[i] - 1). O(n).

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // swap number at position i to position (nums[i] - 1). O(n).
        for (int i = 0; i < nums.size(); i ++) 
            while (nums[i] != nums[nums[i] - 1]) swap(nums[i], nums[nums[i] - 1]);
        vector<int> res;
        for (int i = 0; i < nums.size(); i ++)
            if (nums[i] != i + 1) res.push_back(nums[i]);
        return res;
    }
};