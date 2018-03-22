#include <iostream>
#include <vector>

using namespace std;
/** O(n)空间
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int, bool> mp;
        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i] > 0) {
                mp[nums[i]] = true;
            } 
        }
        for (int i = 1; ; i ++) {
            if (!mp.count(i)) return i;
        }
    }
};
*/

/*O(1)空间，类似寻找1-n中哪些数字没有出现过*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int j = 0;
        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i] > 0) swap(nums[j ++], nums[i]);
        }
        for (int i = 0; i < j; i ++) {
            if (abs(nums[i]) > j) continue;
            nums[abs(nums[i]) - 1] = -abs(nums[abs(nums[i]) - 1]);
        }
        for (int i = 0; i < j; i ++) {
            // cout << i << " " << nums[i] << endl;
            if (nums[i] > 0) return i + 1;
        }
        return j + 1;
    }
};

int main() {
    int a[] = {0,1,2};
    vector<int> v(a, a + 3);
    cout << Solution().firstMissingPositive(v) << endl;
    return 0;
}