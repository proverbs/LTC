class Solution {
public:
    int firstUniqChar(string s) {
        int res = -1;
        vector<int> pos(26, -1);
        vector<int> cs(26, 0);
        for (int i = s.length() - 1; i >= 0; i --) {
            pos[s[i] - 'a'] = i;
            cs[s[i] - 'a'] ++;
        }
        for (int i = 0; i < s.length(); i ++) {
            if (cs[s[i] - 'a'] == 1) return i;
        }
        return res;
    }
};