// classic: high-precision multiplication

class Solution {
public:
    string multiply(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string res;
        for (int i = 0; i < num1.length() + num2.length(); i ++) {
            res.push_back('0');
        }
        
        for (int i = 0; i < num1.length(); i ++) {
            int jin = 0;
            for (int j = 0; j < num2.length(); j ++) {
                int x = (num1[i] - '0') * (num2[j] - '0') + jin;
                x += res[i + j] - '0';
                jin = x / 10;
                res[i + j] = x % 10 + '0';
            }
            if (jin) res[i + num2.length()] = jin + '0';
        }
        
        while (res.length() != 1 && res[res.length() - 1] == '0') res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};