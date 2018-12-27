// prefix sum

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        k = abs(k);
        if (k == 0) {
            for (int i = 0; i < nums.size() - 1; i ++)
                if (!nums[i] && !nums[i + 1]) return true;
            return false;
        }
        if (k == 1) return nums.size() >= 2;
        map<int, int> mod;
        int last = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); i ++) {
            sum += nums[i];
            sum %= k;
            if (mod.count(sum)) return true;
            if (!mod.count(last)) mod[last] = 0;
            mod[last] ++; // delay insert
            last = sum;
        }
        return false;
    }
};