/*反向归并*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int cnt = n + m - 1;
        int l1 = m - 1, l2 = n - 1;
        while (l1 >= 0 || l2 >= 0) {
            if (l1 < 0) nums1[cnt --] = nums2[l2 --];
            else if (l2 < 0) nums1[cnt --] = nums1[l1 --];
            else {
                if (nums1[l1] < nums2[l2]) nums1[cnt --] = nums2[l2 --];
                else nums1[cnt --] = nums1[l1 --];
            }
        }
    }
};