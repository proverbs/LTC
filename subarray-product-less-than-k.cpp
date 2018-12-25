// O(n), sliding window
// it is also a good idea to use binary search by convert the problem to subarray products to subarray sums

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int res = 0;
        int rt = 0;
        long long mul = 1LL;
        for (int i = 0; i < nums.size(); i ++) {
            while (rt != nums.size() && mul * nums[rt] < k) mul *= nums[rt ++];
            if (rt == i) rt ++;
            else {
                res += rt - i;
                mul /= nums[i];
            }
        }
        return res;
    }
};