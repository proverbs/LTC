// binary search the result
// dp is also a solution, although it is O(n^2m)

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long long sum = 0;
        for (int a : nums) sum += a;
        long long lt = nums[0], rt = sum;
        int res;
        while (lt <= rt) {
            int mid = lt + rt >> 1;
            if (check(nums, mid) <= m) rt = mid - 1, res = mid;
            else lt = mid + 1;
        }
        return res;
    }
    
    int check(vector<int> nums, long long cap) {
        long long sm = 0, res = 0;
        for (int a : nums) {
            if (a > cap) return 999999;
            if (a + sm > cap) res ++, sm = a;
            else sm += a;
        }
        return res + 1;
    }
};