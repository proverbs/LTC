// first greater element on the right in O(n)

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        unordered_map<int, int> ng;
        stack<int> stk;
        for (int i = nums.size() - 1; i >= 0; i --) {
            while (!stk.empty() && stk.top() <= nums[i]) stk.pop();
            if (stk.empty()) ng[nums[i]] = -1;
            else ng[nums[i]] = stk.top();
            stk.push(nums[i]);
        }
        vector<int> res;
        for (int a : findNums) res.push_back(ng[a]);
        return res;
    }
};