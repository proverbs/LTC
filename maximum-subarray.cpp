/*dp*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        if (nums.empty()) return 0;
        dp[0] = nums[0];
        int res = dp[0];
        for (int i = 0; i < nums.size(); i ++) {
            dp[i] = max(dp[i - 1], 0) + nums[i];
            res = max(res, dp[i]);
        }
        return res;
    }
};

/**
 * optimized by not using additional array
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        int sum = 0;
        for (int i = 0; i < nums.size(); i ++) {
            sum = max(0, sum) + nums[i];
            res = max(sum, res);
        }
        return res;
    }
};

/**
 * divide and conquer
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return calc(nums, 0, nums.size() - 1);
    }
    
    int calc(vector<int>& nums, int lt, int rt) {
        if (lt == rt) return nums[lt];
        int mid = lt + rt >> 1;
        
        int lt_max = calc(nums, lt, mid);
        int rt_max = calc(nums, mid + 1, rt);
        
        int lt_sum = 0, lt_sum_max = nums[mid];
        for (int i = mid; i >= 0; i --) {
            lt_sum += nums[i];
            lt_sum_max = max(lt_sum_max, lt_sum);
        }
        int rt_sum = 0, rt_sum_max = nums[mid + 1];
        for (int i = mid + 1; i <= rt; i ++) {
            rt_sum += nums[i];
            rt_sum_max = max(rt_sum_max, rt_sum);
        }
        return max(lt_sum_max + rt_sum_max, max(lt_max, rt_max));
    }
};