class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        for (int i = 0; i < n - k; i ++)
            nums.push_back(nums[i]);
        for (int i = 0; i < n; i ++)
            nums[i] = nums[i + n - k];
        for (int i = 0; i < n - k; i ++)
            nums.pop_back();
    }
};

// Cyclic Replacements without using extra space
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int cnt = 0, n = nums.size();
        for (int i = 0; cnt < n; i++) {
            int src = i, dst = (i + k) % n;
            cnt ++;
            while (src != dst) {
                swap(nums[src], nums[dst]);
                cnt ++;
                dst = (dst + k) % n;
            }
        }
    }
};

// reverse
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};