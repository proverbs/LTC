// typical: three-way-partition + virtual indexing
// to get wiggle sort, you want to put the number in the following way such that
// (1) elements smaller than the 'median' are put into the last even slots
// (2) elements larger than the 'median' are put into the first odd slots
// (3) the medians are put into the remaining slots.
// ref: https://leetcode.com/problems/wiggle-sort-ii/discuss/77682/Step-by-step-explanation-of-index-mapping-in-Java

class Solution {
public:
    int n;
    void wiggleSort(vector<int>& nums) {
        n = nums.size();
        // get median
        vector<int>::iterator m_ptr = nums.begin() + n / 2;
        nth_element(nums.begin(), m_ptr, nums.end());
        int m_val = nums[n / 2];
        reverse(nums.begin(), nums.end());
        
        // three-way-partition
        int i = 0, j = 0, k = n;
        while (j < k) {
            if (nums[idx(j)] > m_val) 
                swap(nums[idx(i ++)], nums[idx(j ++)]);
            else if (nums[idx(j)] < m_val)
                swap(nums[idx(j)], nums[idx(-- k)]);
            else j ++;
        }
    }
    
    // virtual indexing
    int idx(int x) {
        int z = x << 1 | 1;
        if (z >= n) z %= (n | 1);
        return z;
    }
};