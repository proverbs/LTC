// check group by group

class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        int res = 0;
        for (string& wd: words)
            if (check(S, wd)) res ++;
        return res;
    }
    
    bool check(string& s, string& wd) {
        int sp = 0, wdp = 0;
        while (sp < s.length() && wdp < wd.length()) {
            if (s[sp] != wd[wdp]) return false;
            int ext_sp = sp, ext_wdp = wdp;
            while (ext_sp + 1 < s.length() && s[ext_sp + 1] == s[sp]) ext_sp ++;
            while (ext_wdp + 1 < wd.length() && wd[ext_wdp + 1] == wd[wdp]) ext_wdp ++;
            if (ext_sp - sp + 1 <= 2) {
                if (ext_wdp - wdp + 1 != ext_sp - sp + 1) return false;
            } else {
                if (ext_wdp - wdp + 1 > ext_sp - sp + 1) return false;
            }
            sp = ext_sp + 1;
            wdp = ext_wdp + 1;
        }
        return sp == s.length() && wdp == wd.length();
    }
};