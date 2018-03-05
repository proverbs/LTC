/*monotonicity*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        if (prices.size() == 0) return res;
        int mi = prices[0];
        for (int i = 1; i < prices.size(); i ++) {
            if (prices[i] > mi) res = max(res, prices[i] - mi);
            else mi = prices[i];
        }
        return res;
    }
};