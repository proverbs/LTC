/*unordered_map+logn的第k大*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i ++) {
            if (mp.count(nums[i])) mp[nums[i]] ++;
            else mp[nums[i]] = 1;
        }
        vector<int> v;
        for (unordered_map<int, int>::iterator it = mp.begin(); it != mp.end(); it ++) {
            v.push_back(it->second);
        }
        int z = search(v, 0, v.size() - 1, v.size() - k + 1);
        vector<int> res;
        for (unordered_map<int, int>::iterator it = mp.begin(); it != mp.end(); it ++) {
            if (it->second >= z) res.push_back(it->first);
        }
        return res;
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
    int a[] = {3,0,1,0};
    vector<int> b(a, a + 4);
    Solution().topKFrequent(b, 1);
    return 0;
}