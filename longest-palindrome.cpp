class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> ct;
        for (char c: s) {
            if (ct.count(c)) ct[c] ++;
            else ct[c] = 1;
        }
        
        int fg = 0;
        int res = 0;
        for (auto& pr: ct) {
            if (pr.second & 1) fg = 1;
            res += pr.second / 2 * 2;
        }
        return res + fg;
    }
};