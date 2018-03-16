/*brute force*/

class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        for (int i = 0; i < s.length(); i ++) {
            res += cnt(s, i, i);
            if (i + 1 < s.length()) res += cnt(s, i, i + 1);
        }
        return res;
    }

    int cnt(string& s, int x, int y) {
        int dt = 0;
        int res = 0;
        while (x - dt >= 0 && y + dt < s.length()) {
            if (s[x - dt] == s[y + dt]) res ++;
            else break;
            dt ++;
        }
        return res;
    }
};