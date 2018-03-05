/*dp + map*/
/*unordered_map是hash map, O(1)，key无序存储; map是红黑树*/
/*此外，还有一个关于map count的小trick*/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> dp;
        unordered_map<int, int> mp;
        for (int i = nums.size() - 1; i >= 0; i --) mp[nums[i]] = i;
        int res = 0;
        for (int i = 0; i < nums.size(); i ++) {
            //dp[nums[i]] = dfs(nums[i], dp, mp); // !!!此处没有赋值之前nums[i]也可被count
            dfs(nums[i], dp, mp);
            res = max(res, dp[nums[i]]);
        }
        return res;
    }

    int dfs(int x, unordered_map<int, int>& dp, unordered_map<int, int>& mp) {
        if (dp.count(x)) return dp[x];
        dp[x] = 1;
        if (mp.count(x + 1)) dp[x] = dfs(x + 1, dp, mp) + 1;
        return dp[x];
    }
};