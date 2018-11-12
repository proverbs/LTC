/*hash*/

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> mp;
        int sz = nums.size();
        for (int i = 0; i < sz; i++) {
            if (mp.count(target - nums[i]) > 0) {
                res.push_back(mp[target - nums[i]]);
                res.push_back(i);
                return res;
            }
            mp[nums[i]] = i;
        }
    }
};

int main() {
    int a[] = {2, 7, 11, 15};
    vector<int> nums(a, a + 4);
    int ta = 22;
    Solution s = Solution();
    vector<int> v = s.twoSum(nums, ta);
    cout << v[0] << "  " << v[1] << endl;
    return 0;
}