/*将数组看成链表*/
/*typical*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<bool> vis(nums.size() + 1, false);
        for (int i = 0; i < nums.size(); i ++) {
            vis[nums[i]] = true;
        }
        vector<int> res;
        for (int i = 1; i <= nums.size(); i ++)
            if (!vis[i]) res.push_back(i);
        return res;
    }
};