/*set*/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        multiset<int> st;
        for (int i = 0; i < nums.size(); i ++) st.insert(nums[i]);
        int lt;
        for (lt = 0; lt < nums.size(); lt ++) {
            if (*st.begin() < nums[lt]) break;
            st.erase(st.find(nums[lt]));
        }
        if (lt == nums.size()) return 0;
        st.clear();
        for (int i = 0; i < nums.size(); i ++) st.insert(nums[i]);
        int rt;
        for (rt = nums.size() - 1; rt >= 0; rt --) {
            if (*st.rbegin() > nums[rt]) break;
            st.erase(st.find(nums[rt]));
        }
        return rt - lt + 1;
    }
};