// typical: d is mono-increasing(not decreasing)

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> d(n, 0);
        int rg = 1;
        for (int i = 0; i < n; i ++) {
            while (rg < n && rg <= i + nums[i]) d[rg ++] = d[i] + 1;
        }
        return d[n - 1];
    }
};