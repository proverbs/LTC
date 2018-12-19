class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int lt = 0; 
        int rt = 0;
        map<char, int> ct;
        // init
        for (int i = 0; i < 26; i ++) {
            ct[i + 'a'] = ct[i + 'A'] = 0;
        }
        int cnt = 0;
        while (rt < s.length()) {
            if (ct[s[rt]] == 0) {
                if (cnt == 2) {
                    break;
                } else {
                    cnt ++;
                    ct[s[rt ++]] ++;
                }
            } else {
                ct[s[rt ++]] ++;
            }
        }
        
        int res = rt - lt;
        while (rt < s.length()) {
            // move left pointer
            while (lt < rt && -- ct[s[lt ++]] != 0);
            cnt --;
            
            // move right pointer
            while (rt < s.length()) {
                if (ct[s[rt]] == 0) {
                    if (cnt == 2) {
                        break;
                    } else {
                        cnt ++;
                        ct[s[rt ++]] ++;
                    }
                } else {
                    ct[s[rt ++]] ++;
                }
            }
            
            res = max(res, rt - lt);
        }
        
        return res;
    }
};