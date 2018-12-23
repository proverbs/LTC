/*deque, monotonic queue*/
/*typical*/

#include <deque>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;
        for (int i = 0; i < nums.size(); i ++) {
            while (!dq.empty() && dq.front() < i - k + 1) dq.pop_front();
            while (!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
            dq.push_back(i);
            if (i >= k - 1) res.push_back(nums[dq.front()]);
        }
        return res;
    }
};

int main() {
    int a[] = {7, 2, 4};
    vector<int> b(a, a + 3);
    cout << Solution().maxSlidingWindow(b, 2)[0] << endl;
    return 0;
}