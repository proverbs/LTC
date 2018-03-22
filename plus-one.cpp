/*类似高精度加法的计算方法*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int jin = 1;
        for (int i = digits.size() - 1; i >= 0; i --) {
            digits[i] = digits[i] + jin;
            jin = digits[i] / 10;
            digits[i] %= 10;
        }
        vector<int> res;
        if (jin) res.push_back(jin);
        for (int i = 0; i < digits.size(); i ++) res.push_back(digits[i]);
        return res;
    }
};