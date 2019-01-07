// greedy

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ns = s.length();
        int nt = t.length();
        if (ns == 0) return true;
        if (nt == 0) return ns == 0;
        int ps = 0, pt = 0;
        while (ps < ns && pt < nt) {
            if (s[ps] == t[pt]) ps ++, pt ++;
            else pt ++;
        }
        return ps == ns;
    }
};