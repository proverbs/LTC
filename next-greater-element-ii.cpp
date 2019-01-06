// repeat the array at the end

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res;
        if (!nums.size()) return res;
        int n = nums.size();
        res.resize(n, 0);
        for (int i = 0; i < n - 1; i ++) nums.push_back(nums[i]);
        nums.push_back(2147483647);
        stack<int> stk;
        stk.push(n + n - 1);
        for (int i = n + n - 2; i >= 0; i --) {
            while (nums[stk.top()] <= nums[i]) stk.pop();
            if (i < n) res[i] = stk.top() == n + n - 1 ? -1 : nums[stk.top()];
            stk.push(i);
        }
        return res;
    }
};