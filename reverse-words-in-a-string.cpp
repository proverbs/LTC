class Solution {
public:
    void reverseWords(string &s) {
        // deal with leading and trailing spaces
        while (s[s.length() - 1] == ' ') s.pop_back();
        reverse(s, 0, s.length() - 1);
        while (s[s.length() - 1] == ' ') s.pop_back();
        reverse(s, 0, s.length() - 1);
        
        // deal with consecutive spaces
        int sumlen = 0;
        for (int i = 0; i < s.length(); i ++) {
            if (s[i] == ' ') {
                int len = 0;
                while (s[i + len] == ' ') len ++;
                i = i + len - 1;
                sumlen += len - 1;
            } else if (sumlen != 0) {
                s[i - sumlen] = s[i];
                s[i] = ' '; // important
            }
        }
        while (sumlen --) s.pop_back();
        // cout << s << endl;
        
        // reverse
        int lt = 0;
        while (lt < s.length()) {
            while (lt < s.length() && s[lt] == ' ') lt ++;
            if (lt == s.length()) break;
            int rt = lt + 1;
            while (rt < s.length() && s[rt] != ' ') rt ++;
            reverse(s, lt, rt - 1);
            lt = rt;
        }
        // cout << s << endl;
        reverse(s, 0, s.length() - 1);
    }
    
    void reverse(string &s, int lt, int rt) {
        while (lt < rt) {
            swap(s[lt], s[rt]);
            lt ++;
            rt --;
        }
    }
};