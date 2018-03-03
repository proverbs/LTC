/*
每一个位置装水量取决于其左右两边最高的板块的高度
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int sz = height.size();
        if (sz == 0) return 0;
        vector<int> lm(sz, 0);
        vector<int> rm(sz, 0);
        lm[0] = 0;
        for (int i = 1; i < sz; i ++) {
            lm[i] = max(height[i - 1], lm[i - 1]);
        }
        rm[sz - 1] = 0;
        for (int i = sz - 2; i >= 0; i --) {
            rm[i] = max(height[i + 1], rm[i + 1]);
        }

        int res = 0;
        for (int i = 0; i < sz; i ++) {
            res += max(min(lm[i], rm[i]), height[i]) - height[i];
        }
        return res;
    }
};

int main() {
    int a[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> v(a, a + 12);
    cout << Solution().trap(v) << endl;
    return 0;
}