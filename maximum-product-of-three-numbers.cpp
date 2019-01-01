// maximum is either x*maximum or x*minimum

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max1 = max(nums[0], nums[1]), min1 = min(nums[0], nums[1]);
        int max2 = nums[0] * nums[1], min2 = max2;
        int res = nums[0] * nums[1] * nums[2];
        
        for (int i = 2; i < nums.size(); i ++) {
            res = max(res, nums[i] * max2);
            res = max(res, nums[i] * min2);
            
            max2 = max(max2, nums[i] * max1);
            max2 = max(max2, nums[i] * min1);
            min2 = min(min2, nums[i] * max1);
            min2 = min(min2, nums[i] * min1);
            
            max1 = max(max1, nums[i]);
            min1 = min(min1, nums[i]);
        }
        
        return res;
    }
};