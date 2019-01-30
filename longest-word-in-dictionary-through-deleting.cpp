// check subsequnce

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end());
        string res = "";
        for (string& wd: d) 
            if (wd.length() > res.length()) 
                if (check(s, wd)) res = wd;
        return res;
    }
    // O(n) check subsequence
    bool check(string& s, string& wd) {
        int p = 0;
        for (int i = 0; i < wd.size(); i ++) {
            while (p < s.length() && s[p] != wd[i]) p ++;
            if (p == s.length()) return false;
            p ++;
        }
        return true;
    }
};