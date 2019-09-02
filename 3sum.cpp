/*remove duplicate, monotonicity(2 pointer)*/

#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > res; 
        map<int, int> ct;
        for (int i = 0; i < nums.size(); i++) {
            if (!ct.count(nums[i])) ct[nums[i]] = 1;
            else ct[nums[i]] += 1;
        }
        sort(nums.begin(), nums.end());
        int sz = unique(nums.begin(), nums.end()) - nums.begin();
        
        for (int i = 0; i < sz; i++) {
            int sm = -nums[i];
            int j = sz - 1;
            for (int k = i; k < sz; k++) {
                while (k < j && nums[j] + nums[k] > sm) j --; //two pointer
                if (nums[j] + nums[k] == sm) {
                    check(nums[i], nums[k], nums[j], ct, res);
                }
            }
        }
        return res;
    }

    void check(int x, int y, int z, map<int, int>& ct, vector<vector<int> >& res) { // x <= y <= z
        if (x == z) {
            if (ct[x] >= 3) add(x, y, z, res);
        }
        else if (x == y) {
            if (ct[x] >= 2 && ct[z] >= 1) add(x, y, z, res);
        }
        else if (y == z) {
            if (ct[y] >= 2 && ct[x] >= 1) add(x, y, z, res);
        }
        else add(x, y, z, res);
    }

    void add(int x, int y, int z, vector<vector<int> >& res) {
        vector<int> v;
        v.push_back(x);
        v.push_back(y);
        v.push_back(z);
        res.push_back(v);
    }
};

int main() {
    int a[] = {1,1,-2};
    vector<int> t(a, a + 3);
    cout << Solution().threeSum(t).size() << endl;
    return 0;
}

/**
 * optimized using 2 pointers
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        for (int i = 0; i < n; ) {
            int lt = i + 1;
            int rt = n - 1;
            while (rt > lt && nums[lt] + nums[rt] > -nums[i]) rt --;
            while (lt < rt) {
                if (nums[i] + nums[lt] + nums[rt] == 0) {
                    vector<int> t;
                    t.push_back(nums[i]);
                    t.push_back(nums[lt]);
                    t.push_back(nums[rt]);
                    res.push_back(t);
                }
                lt ++;
                while (lt < rt && nums[lt] == nums[lt - 1]) lt ++;
                while (rt > lt && nums[lt] + nums[rt] > -nums[i]) rt --;
            }
            i ++;
            while (i < n && nums[i] == nums[i - 1]) i ++;
        }
        return res;
    }
};