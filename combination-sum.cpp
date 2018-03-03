/*dfs, brute force*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > res;
        vector<int> e;
        dfs(e, candidates, 0, target, res);
        return res;
    }

    void dfs(vector<int>& e, vector<int>& can, int idx, int target, vector<vector<int> >& res) {
        if (target == 0) res.push_back(e);
        if (idx >= can.size()) return;
        if (can[idx] <= target){
            e.push_back(can[idx]);
            dfs(e, can, idx, target - can[idx], res);
            e.pop_back();

            dfs(e, can, idx + 1, target, res);
        }
    }
};

int main() {
    int a[] = {2, 3, 6, 7};
    vector<int> v(a, a + 4);
    cout << Solution().combinationSum(v, 7).size() << endl;
    return 0;
}