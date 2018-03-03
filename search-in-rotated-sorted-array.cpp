/*binary search*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int sz = nums.size();
        if (sz == 0) return -1;
        int lt = 0, rt = sz - 1;
        int pv; // index of the minimum number
        while (lt <= rt) {
            int mid = (lt + rt) >> 1;
            if (nums[mid] > nums[sz - 1]) {
                lt = mid + 1;
                pv = lt; // important
            } else {
                rt = mid - 1;
                pv = mid; // important
            }
        }
        // cout << pv << endl;
        if (target > nums[sz - 1]) lt = 0, rt = pv - 1;
        else lt = pv, rt = sz - 1;
        while (lt <= rt) {
            int mid = (lt + rt) >> 1;
            if (nums[mid] == target) return mid;
            if (nums[mid] < target) lt = mid + 1;
            else rt = mid - 1;
        }
        return -1;
    }
};

int main() {
    int a[] = {4,5,6,7,0,1,2};
    vector<int> v(a, a + 2);
    cout << Solution().search(v, 1) << endl;
    return 0;
}