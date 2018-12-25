// O(n)

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> cs(26, 0);
        for (int i = 0; i < s.length(); i ++) {
            cs[s[i] - 'a'] ++;
        }
        vector<int> bs(26, 0);
        for (int i = 0; i < t.length(); i ++) {
            bs[t[i] - 'a'] ++;
        }
        for (int i = 0; i < 26; i ++) {
            if (cs[i] != bs[i]) return false;
        }
        return true;
    }
};