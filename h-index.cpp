// A better O(n) method: https://leetcode.com/problems/h-index/solution/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int res = 0;
        for (int i = 1; i <= citations.size(); i ++)
            if (citations.size() - (lower_bound(citations.begin(), citations.end(), i) - citations.begin()) >= i) 
                res = max(res, i);
        return res;
    }
};