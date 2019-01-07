// consider 2d table from nums1 x nums2
// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/discuss/84550/Slow-1-liner-to-Fast-solutions


class Solution {
public:
    typedef pair<int, int> pr;
    typedef pair<int, pr> pr2;
    class Compare {
    public:
        bool operator() (const pr2& a, const pr2& b) {
            return a.first > b.first;
        }
    };
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pr2, vector<pr2>, Compare> q;
        vector<pr> res;
        if (nums1.size() == 0 || nums2.size() == 0) return res;
        for (int i = 0; i < min((int)nums1.size(), k); i ++) 
            q.push({nums1[i] + nums2[0], {i, 0}});
        
        while (res.size() < min(k, (int)nums1.size() * (int)nums2.size())) {
            int p1 = q.top().second.first;
            int p2 = q.top().second.second;
            q.pop();
            res.push_back({nums1[p1], nums2[p2]});
            if (p2 + 1 < nums2.size()) 
                q.push({nums1[p1] + nums2[p2 + 1], {p1, p2 + 1}});
        }
        return res;
    }
};