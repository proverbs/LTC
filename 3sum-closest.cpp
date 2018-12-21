// two pointers

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i ++) {
            int lt = i, rt = nums.size() - 1;
            while (lt < rt) {
                lt ++;
                while (lt < rt && nums[i] + nums[lt] + nums[rt] > target) rt --;
                if (lt < rt) {
                    if (nums[i] + nums[lt] + nums[rt] == target) return target;
                    else {
                        if (abs(nums[i] + nums[lt] + nums[rt] -target) < abs(res - target)) {
                            res = nums[i] + nums[lt] + nums[rt];
                        } else if (rt + 1 < nums.size() && abs(nums[i] + nums[lt] + nums[rt + 1] -target) < abs(res - target)) {
                            res = nums[i] + nums[lt] + nums[rt + 1];
                        }
                    } 
                } else if (rt + 1 < nums.size()) {
                    if (abs(nums[i] + nums[lt] + nums[rt + 1] -target) < abs(res - target)) {
                        res = nums[i] + nums[lt] + nums[rt + 1];
                    }
                }
            }
        }
        return res;
    }
};