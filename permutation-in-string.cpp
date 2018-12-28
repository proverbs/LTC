class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> cs(26, 0);
        int zero = 26;
        int len = s1.length();
        for (int i = 0; i < len; i ++) 
            if (cs[s1[i] - 'a'] ++ == 0) zero --;
        for (int i = 0; i < s2.length(); i ++) {
            if (cs[s2[i] - 'a'] == 0) zero --;
            else if (cs[s2[i] - 'a'] == 1) zero ++;
            cs[s2[i] - 'a'] --;
            
            if (i >= len) {
                if (cs[s2[i - len] - 'a'] == 0) zero --;
                else if (cs[s2[i - len] - 'a'] == -1) zero ++;
                cs[s2[i - len] - 'a'] ++;
            }
            
            if (zero == 26) return true;
        }
        return false;
    }
};