// classsic: same as find-median-from-data-stream
// remove can be implemented using set


#include <set>

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        multiset<int> max_heap;
        multiset<int> min_heap;
        multiset<int>::iterator it, ib;
        for (int i = 0; i < nums.size(); i ++) {
            // add
            max_heap.insert(nums[i]);
            it = max_heap.end();
            it --;
            int z = *it;
            max_heap.erase(it);
            
            min_heap.insert(z);
            
            if (max_heap.size() < min_heap.size()) {
                it = min_heap.begin();
                z = *it;
                min_heap.erase(it);
                max_heap.insert(z);
            }
            
            if (i >= k - 1) {
                it = max_heap.end();
                it --;
                if (max_heap.size() > min_heap.size()) {
                    res.push_back(1.0 * (*it));
                } else {
                    ib = min_heap.begin();
                    long long lit = *it;
                    long long lib = *ib;
                    res.push_back(0.5 * (lit + lib));
                }
                
                // delete
                it = max_heap.end();
                it --;
                if (nums[i - k + 1] > *it) {
                    min_heap.erase(min_heap.find(nums[i - k + 1]));
                    if (min_heap.size() != max_heap.size()) {
                        min_heap.insert(*it);
                        max_heap.erase(it);
                    }
                } else {
                    max_heap.erase(max_heap.find(nums[i - k + 1]));
                    if (max_heap.size() < min_heap.size()) {
                        it = min_heap.begin();
                        max_heap.insert(*it);
                        min_heap.erase(it);
                    }
                }
            }
        }
        return res;
    }
};