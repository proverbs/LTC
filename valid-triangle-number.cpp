// two pointers, like 3sum

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0; i < nums.size(); i ++) { // shortest side
            int lt = i + 1, rt = lt + 1;
            while (lt < nums.size()) {
                rt = max(lt + 1, rt);
                while (rt < nums.size() && nums[i] + nums[lt] > nums[rt]) rt ++;
                res += rt - lt - 1;
                lt ++; 
            }
        }
        return res;
    }
};