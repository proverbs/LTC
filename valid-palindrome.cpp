/*遍历*/

class Solution {
public:
    bool isPalindrome(string s) {
        int lt = 0, rt = s.length() - 1;
        while (lt <= rt) {
            while (lt <= rt && !(toChar(s[lt]) >= 'a' && toChar(s[lt]) <= 'z') && !(s[lt] >= '0' && s[lt] <= '9')) lt ++;
            while (lt <= rt && !(toChar(s[rt]) >= 'a' && toChar(s[rt]) <= 'z') && !(s[rt] >= '0' && s[rt] <= '9')) rt --;
            if (lt > rt) break;
            if (toChar(s[lt]) != toChar(s[rt])) return false;
            else {
                lt ++;
                rt --;
            }
        }
        return true;
    }

    char toChar(char x) {
        if (x >= 'A' && x <= 'Z') return x - 'A' + 'a';
        if (x >= 'a' && x <= 'z') return x;
        return x;
    }
};