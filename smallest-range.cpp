// merge k ordered list

class Solution {
public:
    typedef pair<int, int> pr; // <val, idx>
    
    class Compare {
    public:
        bool operator() (const pr& a, const pr& b) {
            return a.first > b.first;
        }
    };
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pr, vector<pr>, Compare> lt;
        vector<int> ptr;
        
        int res_lt = 999999, res_rt = -999999;
        for (int i = 0; i < nums.size(); i ++) {
            lt.push({nums[i][0], i});
            ptr.push_back(1);
            res_lt = min(res_lt, nums[i][0]);
            res_rt = max(res_rt, nums[i][0]);
        }
        
        int cur_rt = res_rt;
        while (true) {
            int idx = lt.top().second;
            lt.pop();
            if (ptr[idx] == nums[idx].size()) break;
            lt.push({nums[idx][ptr[idx]], idx});
            cur_rt = max(cur_rt, nums[idx][ptr[idx]]);
            ptr[idx] ++;
            if (res_rt - res_lt > cur_rt - lt.top().first) 
                res_rt = cur_rt, res_lt = lt.top().first;
        }
        return vector<int>({res_lt, res_rt});
    }
};