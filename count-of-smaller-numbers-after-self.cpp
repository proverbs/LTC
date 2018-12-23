/*树状数组*/
/*typical, 逆序对*/
/*还有一种分治的方法*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define lowbit(x) x & -x

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> sn(nums.size(), 0);
        vector<int> pn(nums.begin(), nums.end());
        sort(pn.begin(), pn.end());
        int sz = unique(pn.begin(), pn.end()) - pn.begin();
        for (int i = 0; i < nums.size(); i ++) {
            sn[i] = lower_bound(pn.begin(), pn.begin() + sz, nums[i]) - pn.begin();
        }
        vector<int> t(sz + 2, 0);
        vector<int> res(sn.size(), 0);
        for (int i = sn.size() - 1; i >= 0; i --) {
            res[i] = getsum(t, sn[i]);
            update(t, sn[i] + 1, 1);
        }
        return res;
    }

    void update(vector<int>& t, int pos, int val) {
        for (int i = pos; i < t.size(); i += lowbit(i)) {
            t[i] += val;
        }
    }

    int getsum(vector<int>& t, int pos) {
        int sum = 0;
        for (int i = pos; i > 0; i -= lowbit(i)) {
            sum += t[i];
        }
        return sum;
    }
};

int main() {
    int a[] = {5,2,6,1};
    vector<int> v(a, a + 4);
    Solution().countSmaller(v);
    return 0;
}