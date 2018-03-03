/*binary search*/
// lower_bound, upper_bound

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int resl = nums.size(), resr = nums.size(); // init is important
        int lt = 0, rt = nums.size() - 1;
        while (lt <= rt) {
            int mid = lt + rt >> 1;
            if (nums[mid] > target) rt = mid - 1, resr = mid; // 收束方向与初始化一致
            else lt = mid + 1;
        }
        lt = 0, rt = nums.size() - 1;
        while (lt <= rt) {
            int mid = lt + rt >> 1;
            if (nums[mid] >= target) rt = mid - 1, resl = mid;
            else lt = mid + 1;
        }
        vector<int> res(2, -1);
        if (resl < resr) res[0] = resl, res[1] = resr - 1;
        return res; 
    }
};

int main() {

}