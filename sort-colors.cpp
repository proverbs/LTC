/*count*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int ct[3];
        ct[0] = ct[1] = ct[2] = 0;
        for (int i = 0; i < nums.size(); i ++) ct[nums[i]] ++;
        for (int i = 0; i < nums.size(); i ++) {
            if (i < ct[0]) nums[i] = 0;
            else if (i < ct[0] + ct[1]) nums[i] = 1;
            else nums[i] = 2;
        }
    }
};