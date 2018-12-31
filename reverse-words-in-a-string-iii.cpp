class Solution {
public:
    string reverseWords(string s) {
        int lt = 0, rt;
        while (lt < s.length()) {
            rt = lt;
            while (rt < s.length() && s[rt] != ' ') rt ++;
            reverse(s.begin() + lt, s.begin() + rt);
            lt = rt + 1;
        }
        return s;
    }
};