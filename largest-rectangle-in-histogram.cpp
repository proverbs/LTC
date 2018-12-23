/*stack, dp*/
/*typical, monotone stack*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.size() == 0) return 0;
        stack<pair<int, int> > stk;
        vector<int> lt(heights.size(), 0);
        vector<int> rt(heights.size(), 0);
        stk.push(make_pair(-1, -1));
        for (int i = 0; i < heights.size(); i ++) {
            while (heights[i] <= stk.top().second) stk.pop();
            lt[i] = stk.top().first;
            stk.push(make_pair(i, heights[i]));
        }
        while (!stk.empty()) stk.pop();
        stk.push(make_pair(heights.size(), -1));
        for (int i = heights.size() - 1; i >= 0; i --) {
            while (heights[i] <= stk.top().second) stk.pop();
            rt[i] = stk.top().first;
            stk.push(make_pair(i, heights[i]));
        }
        int res = 0;
        for (int i = 0; i < heights.size(); i ++) {
            res = max(res, (rt[i] - lt[i] - 1) * heights[i]);
        }
        return res;
    }
};