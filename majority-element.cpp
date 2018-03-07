/*bit count*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = 0;
        for (int j = 0; j < 32; j ++) {
            int x = 0;
            for (int i = 0; i < nums.size(); i ++) {
                x += (nums[i] >> j) & 1;
            }
            if (x * 2 > nums.size()) res |= 1 << j;
        }
        return res;
    }
};

int main() {
    int a[] = {3,3,4};
    vector<int> v(a, a + 3);
    cout << Solution().majorityElement(v) << endl;
    return 0;
}