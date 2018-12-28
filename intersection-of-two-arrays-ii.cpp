class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> cs1, cs2;
        for (int x : nums1) {
            if (!cs1.count(x)) cs1[x] = 0;
            cs1[x] ++;
        }
        for (int x : nums2) {
            if (!cs2.count(x)) cs2[x] = 0;
            cs2[x] ++;
        }
        
        vector<int> res;
        for (int x : nums1) {
            if (cs1[x] <= 0) continue;
            if (!cs2.count(x) || cs2[x] <= 0) continue;
            int z = min(cs1[x], cs2[x]);
            for (int i = 0; i < z; i ++) res.push_back(x);
            cs1[x] -= z;
            cs2[x] -= z;
        }
        
        return res;
    }
};