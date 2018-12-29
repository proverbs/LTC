class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> cs, lt, rt;
        int max_feq = 1;
        for (int i = 0; i < nums.size(); i ++) {
            int x = nums[i];
            if (!cs.count(x)) cs[x] = 1, lt[x] = rt[x] = i;
            else {
                max_feq = max(max_feq, ++ cs[x]);
                rt[x] = i;
            }
        }
        int res = nums.size();
        for (int x : nums)
            if (cs[x] == max_feq) 
                res = min(res, rt[x] - lt[x] + 1);
        return res;
    }
};