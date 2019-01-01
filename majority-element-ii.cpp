// extended from moore majority voting

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        if (nums.size() == 0) return res;
        
        int a = nums[0], b = a;
        for (int i = 0; i < nums.size(); i ++)
            if (nums[i] != a) {
                b = nums[i];
                break;
            }
        if (b == a) {
            res.push_back(a);
            return res;
        }
        
        int ca = 0, cb = 0;
        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i] == a) ca ++;
            else if (nums[i] == b) cb ++;
            else {
                if (ca == 0) a = nums[i], ca ++;
                else if (cb == 0) b = nums[i], cb ++;
                else ca --, cb --;
            }
        }
        
        ca = 0, cb = 0;
        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i] == a) ca ++;
            else if (nums[i] == b) cb ++;
        }
        
        if (ca * 3 > nums.size()) res.push_back(a);
        if (cb * 3 > nums.size()) res.push_back(b);
        return res;
    }
};