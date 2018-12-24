// if the result should be in order according to nums1, we can binary serach nums2

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums2.begin(), nums2.end());
        unordered_set<int> st;
        vector<int> res;
        vector<int>::iterator it;
        for (int i = 0; i < nums1.size(); i ++) {
            if (st.count(nums1[i])) continue;
            it = lower_bound(nums2.begin(), nums2.end(), nums1[i]);
            if (it != nums2.end() && *it == nums1[i]) {
                res.push_back(nums1[i]); 
                st.insert(nums1[i]);
            }
        }
        return res;
    }
};