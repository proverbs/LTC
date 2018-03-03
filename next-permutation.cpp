/*none*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int w = -1;
        for (int i = nums.size() - 2; i >= 0; i -- ) {
            if (nums[i] < nums[i + 1]) {
                w = i;
                break;
            }
        }
        if (w == -1) {
            sort(nums.begin(), nums.end());
        }
        else {
            int min_idx, min_val = 99999999;
            for (int i = w + 1; i < nums.size(); i ++) {
                if (nums[i] > nums[w] && nums[i] < min_val) {
                    min_val = nums[i];
                    min_idx = i;
                }
            }
            //cout << min_idx << endl;
            swap(nums[w], nums[min_idx]);
            sort(nums.begin() + w + 1, nums.end());
        }
    }
};

int main() {
    vector<int> x;
    x.push_back(0);
    x.push_back(0);
    x.push_back(4);
    x.push_back(2);
    x.push_back(1);
    x.push_back(0);
    Solution().nextPermutation(x);
    for (int i = 0; i < x.size(); i ++) {
        cout << x[i] << " ";
    }
    return 0;
}