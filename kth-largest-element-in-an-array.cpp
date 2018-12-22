/*divide and conquer, quick sort*/
/*tipical*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return search(nums, 0, nums.size() - 1, nums.size() - k + 1);
    }

    int partition(vector<int>& nums, int lt, int rt) {
        int pi = nums[rt];
        int i = lt - 1;
        for (int j = lt; j < rt; j ++) {
            if (nums[j] <= pi) swap(nums[++ i], nums[j]);
        }
        swap(nums[i + 1], nums[rt]);
        return i + 1;
    }

    int search(vector<int>& nums, int lt, int rt, int k) {
        if (lt < rt) {
            int pos = partition(nums, lt, rt);
            if (pos - lt + 1 == k) return nums[pos];
            else if (pos - lt + 1 > k) {
                return search(nums, lt, pos - 1, k);
            } else {
                return search(nums, pos + 1, rt, k - (pos - lt + 1));
            }
        }
        return nums[lt];
    }
};

int main() {
    int a[] = {7,6,5,4,3,2,1};
    vector<int> v(a, a + 7);
    cout << Solution().findKthLargest(v, 2) << endl;
    return 0;
}