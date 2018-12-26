// two pointers
// followup: shortest-subarray-with-sum-at-least-k

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int lt = -1, sum = 0;
        int res = nums.size() + 1;
        for (int i = 0; i < nums.size(); i ++) {
            sum += nums[i];
            while (sum >= s) {
                res = min(res, i - lt);
                sum -= nums[++ lt];
            }
        }
        
        if (res <= nums.size()) return res;
        return 0;
    }
};