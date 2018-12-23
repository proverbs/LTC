// typical: mono-increasing stack

class Solution {
public:
    string removeKdigits(string num, int k) {
        string res;
        for (int i = 0; i < num.length(); i ++) {
            while (!res.empty() && k && res.back() > num[i]) res.pop_back(), k --;
            res.push_back(num[i]);
        }
        while (!res.empty() && k --) res.pop_back();
        reverse(res.begin(), res.end());
        while (!res.empty() && res.back() == '0') res.pop_back();
        reverse(res.begin(), res.end());
        if (res.empty()) return res = "0";
        return res;
    }
};