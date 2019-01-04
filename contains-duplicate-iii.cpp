// another quite brilliant solution is brucketing, O(n): 
// https://leetcode.com/problems/contains-duplicate-iii/discuss/61645/AC-O(N)-solution-in-Java-using-buckets-with-explanation

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k == 0) return false;
        long long tt = t;
        multiset<int> st;
        for (int i = 0; i < nums.size(); i ++) {
            auto it = st.insert(nums[i]);
            // for (int x : st) cout << x << ", ";
            // cout << endl;
            auto z = it;
            z ++;
            if (z != st.end()) {
                if ((long long)*z - nums[i] <= t) return true;
            }
            z = it;
            if (z != st.begin()) {
                z --;
                if ((long long)nums[i] - *z <= t) return true;
            }
            if (st.size() == k + 1) st.erase(st.find(nums[i - k]));
        }
        return false;
    }
};