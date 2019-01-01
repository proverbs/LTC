// https://blog.csdn.net/cyningsun/article/details/7545679

class Solution {
public:
    vector<int> org, nums;
    Solution(vector<int> nums) : nums(nums), org(nums) {
        
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        for (int i = 0; i < nums.size(); i ++)
            nums[i] = org[i];
        return nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for (int i = 1; i < nums.size(); i ++)
            swap(nums[i], nums[rand() % (i + 1)]);
        return nums;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */