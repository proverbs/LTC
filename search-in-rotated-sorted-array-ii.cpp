class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.size() == 0) return false;
        int lt = 0, rt = nums.size() - 1;
        while (lt <= rt) {
            int mid = lt + rt >> 1;
            if (nums[mid] == target) return true;
            if (nums[mid] < nums[rt]) {
                if (nums[rt] >= target && nums[mid] <= target) lt = mid + 1;
                else rt = mid - 1;
            } else if (nums[mid] > nums[rt]) {
                if (nums[lt] <= target && nums[mid] >= target) rt = mid - 1;
                else lt = mid + 1;
            } else {
                if (nums[lt] == nums[rt]) lt ++, rt --; // trick
                else rt = mid - 1;
            }
        }
        return false;
    }
};