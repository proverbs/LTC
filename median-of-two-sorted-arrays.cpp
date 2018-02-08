/*monotonicity*/

#include <vector>

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        int len = len1 + len2;
        int l1 = 0, l2 = 0;
        int res;
        vector<int> v;
        while (l1 < len1 || l2 < len2) {
            if (l1 < len1 && l2 < len2) {
                if (nums1[l1] < nums2[l2]) res = nums1[l1 ++];
                else res = nums2[l2 ++];
            }
            else if (l1 < len1) res = nums1[l1 ++];
            else res = nums2[l2 ++];
            v.push_back(res);
        }
        return 0.5 * (v[(len - 1) / 2] + v[len / 2]);
    }
};