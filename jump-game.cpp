/*monotonicity*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mxlen = 0;
        for (int i = 0; i < nums.size(); i ++) {
            if (i > mxlen) return false;
            if (i + nums[i] > mxlen) mxlen = i + nums[i];
        }
        return true;
    }
};