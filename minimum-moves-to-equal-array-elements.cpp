// the last state before all elements are equal is (n-1) elements are equal
// the last state before (n-1) elements are equal is (n-2) elements are equal
// ...

class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int add = 0, res = 0;
        for (int i = 1; i < nums.size(); i ++) {
            nums[i] += add;
            res += nums[i] - nums[i - 1];
            add += nums[i] - nums[i - 1];
        }
        return res;
    }
};