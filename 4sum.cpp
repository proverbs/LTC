// (1) O(n^3), similar to 3sum
// (2) O(n^2logn), the following code with set(trick to remove duplications)
// (3) O(n^2), replace set with unordered_set

class Solution {
public:
    typedef pair<int, int> pr;
    unordered_map<int, set<pr>> sum; // unordered_set needs cusomized hash function
    unordered_map<int, int> cs;
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i ++) {
            if (!cs.count(nums[i])) cs[nums[i]] = 0;
            cs[nums[i]] ++;
        }
        
        for (int i = 0; i < nums.size(); i ++) {
            for (int j = i + 1; j < nums.size(); j ++) {
                int x = nums[i], y = nums[j];
                if (x > y) swap(x, y);
                if (!sum.count(x + y)) sum[x + y] = set<pr>();
                sum[x + y].insert({x, y});
            }
        }
        
        vector<vector<int>> res;
        unordered_map<int, set<pr>>::iterator it, is;
        for (it = sum.begin(); it != sum.end(); it ++) {
            int x = it->first, y = target - it->first;
            if (!sum.count(y)) continue;
            is = sum.find(y);
            set<pr>::iterator tx, ty;
            for (tx = it->second.begin(); tx != it->second.end(); tx ++) {
                for (ty = is->second.begin(); ty != is->second.end(); ty ++) {
                    vector<int> ans;
                    ans.push_back(tx->first);
                    ans.push_back(tx->second);
                    ans.push_back(ty->first);
                    ans.push_back(ty->second);
                    if (ans[0] > ans[1] || ans[1] > ans[2] || ans[2] > ans[3]) continue; // trick to remove duplications
                    
                    bool fg = true;
                    
                    for (int i = 0; i < 4; i ++) 
                        if (cs[ans[i]] -- == 0) fg = false;
                    
                    if (fg) {
                        sort(ans.begin(), ans.end());
                        res.push_back(ans);
                    }
                    
                    for (int i = 0; i < 4; i ++) cs[ans[i]] ++;
                }
            }
        }
        
        return res;
    }
};