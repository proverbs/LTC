class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int rt = 0;
        unordered_map<char, int> cs;
        int non_zero = 0;
        int res = 0;
        for (int i = 0; i < s.length(); i ++) {
            // right pointer: move backward
            while (rt < s.length() && non_zero <= k) {
                if (cs.count(s[rt])) cs[s[rt]] ++;
                else {
                    if (non_zero < k) cs[s[rt]] = 1, non_zero ++;
                    else break;
                }
                rt ++;
            }
            res = max(res, rt - i);
            // left pointer: move backward
            if (cs.count(s[i])) {
                if (cs[s[i]] == 1) cs.erase(cs.find(s[i])), non_zero --;
                else cs[s[i]] --;
            } else {
                rt = i + 1;
            }
        }
        return res;
    }
};