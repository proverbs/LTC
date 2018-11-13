// classic: Monotone stack(decreasing)
// find the first larger element
// time complexity: O(n)
// space complexity: O(n)

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> res(T.size(), 0);
        stack<int> stk;
        for (int i = 0; i < T.size(); i ++) {
            // pop
            while (!stk.empty() && T[stk.top()] < T[i]) {
                res[stk.top()] = i - stk.top();
                stk.pop();
            }
            // push
            stk.push(i);
        }
        return res;
    }
};