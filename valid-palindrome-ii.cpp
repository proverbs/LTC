class Solution {
public:
    bool validPalindrome(string s) {
        return is_valid(s, 0, s.length() - 1, 1);
    }
    
    bool is_valid(string &s, int lt, int rt, int k) {
        while (lt < rt && s[lt] == s[rt]) lt ++, rt --;
        if (lt >= rt) return true;
        else if (k) return is_valid(s, lt + 1, rt, k - 1) || is_valid(s, lt, rt - 1, k - 1);
        return false;
    }
};