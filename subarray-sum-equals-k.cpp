/*转换为求两个数的差为定值, hashmap*/
/*typical*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> sum(nums.size(), 0);
        sum[0] = nums[0];
        for (int i = 1; i < nums.size(); i ++) {
            sum[i] = sum[i - 1] + nums[i];
        }
        int res = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for (int i = 0; i < nums.size(); i ++) {
            if (mp.count(sum[i] - k)) res += mp[sum[i] - k];
            add(mp, sum[i]);
        }
        return res;
    }

    void add(unordered_map<int, int>& mp, int x) {
        if (mp.count(x)) mp[x] ++;
        else mp[x] = 1;
    }
};