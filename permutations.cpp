/*dfs, brute force*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> e;
        vector<bool> used(nums.size(), false);
        vector<vector<int> > res;
        dfs(e, used, nums, res);
        return res;
    }

    void dfs(vector<int>& e, vector<bool>& used, vector<int>& nums, vector<vector<int> >& res) {
        if (e.size() == used.size()) {
            res.push_back(e);
            return;
        }
        for (int i = 0; i < used.size(); i ++) {
            if (used[i] == false) {
                used[i] = true;
                e.push_back(nums[i]);
                dfs(e, used, nums, res);
                e.pop_back();
                used[i] = false;
            }
        }
    }
};

int main() {
    int a[] = {1,2,3};
    vector<int> v(a, a + 3);
    cout << Solution().permute(v).size() << endl;
    return 0;
}