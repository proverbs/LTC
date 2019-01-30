// bits
// followup: update a range?

class NumArray {
public:
    vector<int> bits;
    vector<int> nums;
    vector<int> sums;
    int n;
    #define lowbit(x) x & -x
    NumArray(vector<int> nums) : nums(nums) {
        bits.clear();
        n = nums.size();
        bits.resize(n + 1, 0);
        sums.resize(n + 1, 0);
        sums[0] = 0;
        for (int i = 0; i < n; i ++) {
            sums[i + 1] += sums[i] + nums[i];
        }
    }
    
    void update(int i, int val) {
        int tmp = val;
        val = val - nums[i];
        nums[i] = tmp;
        
        for (int x = i + 1; x <= n; x += lowbit(x))
            bits[x] += val;
    }
    
    int sumRange(int i, int j) {
        int res2 = 0, res1 = 0;
        for (int x = i; x; x -= lowbit(x))
            res1 += bits[x];
        for (int x = j + 1; x; x -= lowbit(x))
            res2 += bits[x];
        return res2 - res1 + sums[j + 1] - sums[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */