class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> ct;
        for (char c : s) {
            if (ct.count(c)) ct[c] ++;
            else ct[c] = 1;
        }
        int res = 0;
        for (auto& kv : ct) res += kv.second & 1;
        return res < 2;
    }
};