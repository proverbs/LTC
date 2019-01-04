// typical: reverse pairs using discretization and BIT

class Solution {
public:
    vector<long long> v;
    vector<int> b;
    int sz;
    #define lowbit(x) x & -x
    int reversePairs(vector<int>& nums) {
        v.clear();
        b.clear();
        for (int a : nums) v.push_back(a), v.push_back((long long)a * 2);
        sort(v.begin(), v.end());
        sz = unique(v.begin(), v.end()) - v.begin();
        b.resize(sz + 1, 0);
        
        int res = 0;
        for (int i = 0; i < nums.size(); i ++) {
            res += i - getsum(idx(2LL * nums[i]));
            update(idx(nums[i]));
        }
        return res;
    }
    
    int idx(long long x) {
        return lower_bound(v.begin(), v.begin() + sz, x) - v.begin() + 1;
    }
    
    int getsum(int x) {
        int sum = 0;
        for (int i = x; i; i -= lowbit(i)) sum += b[i];
        return sum;
    }
    
    void update(int x) {
        for (int i = x; i <= sz; i += lowbit(i)) b[i] += 1;
    }
};