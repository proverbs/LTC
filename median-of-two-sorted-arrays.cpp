/*monotonicity*/

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/**O(n)
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
*/
/**
 * log(min(n, m))
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return find(nums2, nums1);
        else return find(nums1, nums2);
    }

    double find(vector<int>& nums1, vector<int>& nums2) {
        const int inf = 99999999;
        vector<int> n1, n2;
        n1.push_back(-inf);
        n2.push_back(-inf);
        n1.push_back(-inf);
        n2.push_back(-inf);
        for (int i = 0; i < nums1.size(); i ++) n1.push_back(nums1[i]);
        for (int i = 0; i < nums2.size(); i ++) n2.push_back(nums2[i]);
        n1.push_back(inf);
        n2.push_back(inf);
        n1.push_back(inf);
        n2.push_back(inf);
        // 首尾增加两个数防止越界
        int len1 = n1.size(), len2 = n2.size();
        int len = len1 + len2;
        int mididx = len - 1 >> 1;
        int lt = 2, rt = len1 - 2;
        while (lt <= rt) {
            int mid = lt + rt >> 1;
            int z = mididx - mid;
            if (n2[z] >= n1[mid - 1] && n1[mid] >= n2[z - 1]) {
                //
                if (len & 1) {
                    return min(n2[z], n1[mid]);
                }
                else {
                    vector<int> t;
                    t.push_back(n1[mid]); t.push_back(n1[mid + 1]);
                    t.push_back(n2[z]); t.push_back(n2[z + 1]);
                    sort(t.begin(), t.end());
                    return 0.5 * (t[0] + t[1]);
                }
            } else {
                
                if (n2[z] < n1[mid - 1]) rt = mid - 1;
                else lt = mid + 1;
            }
        }
    }
};

int main() {
    int a1[] = {1};
    int a2[] = {3, 4};
    vector<int> nums1(a1, a1 + 1);
    vector<int> nums2(a2, a2 + 2);
    cout << Solution().findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}