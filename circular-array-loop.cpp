// bad description.
// [-2, 1, -1, -2, -2] returns false.
// To be a loop, it must never change direction. 
// In other words, the elements of the loop must all have the same sign, either all positive or all negative. 
// If it reverses direction it is an oscillation rather than a loop.


// mark nums[x] as (sign * size) when visiting.
// mark nums[x] as (2 * sign * size) after visiting.

// TC: O(n), SC: O(1)
class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int sz = nums.size();
        for (int i = 0; i < sz; i ++) {
            if (nums[i] < 0) {
                nums[i] = (nums[i] % sz + sz) % sz - sz;
                if (nums[i] == -sz) nums[i] = 0;
            }
            else nums[i] = nums[i] % sz;
        }
        for (int i = 0; i < sz; i ++) {
            if (nums[i] == 2 * sz || nums[i] == -2 * sz) continue;
            if (dfs(nums, i, nums[i] >= 0 ? 1 : -1)) return true;
            for (int j = 0; j < sz; j ++) cout << nums[j] << ", ";
            cout << endl;
        }
        return false;
    }
    
    bool dfs(vector<int>& nums, int x, int sign) {
        int sz = nums.size();
        if (nums[x] * sign <= 0) return false;
        if (nums[x] == 2 * sign * sz) return false;
        if (nums[x] * sign == sz) {
            nums[x] *= 2;
            return true;
        } else {
            int y = (x + nums[x] + nums.size()) % nums.size();
            nums[x] = sz * sign;
            bool fg;
            if (y == x) fg = false; // self-loop
            else fg = dfs(nums, y, sign);
            nums[x] *= 2;
            return fg;
        }
    }
};