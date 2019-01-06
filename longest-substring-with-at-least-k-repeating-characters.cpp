// It is hard to apply sliding window, when we cannot determine how many unique letters should be in the sliding window.
// So, we use 26 sliding windows for defferent numbers of unique letters.

class Solution {
public:
    int longestSubstring(string s, int k) {
        if (!k) return 0;
        int res = 0;
        
        for (int num = 26; num >= 1; num --) {
            vector<int> cs(26, 0);
            int rt = 0;
            int less_k = 0, cnt = 0;
            for (int i = 0; i < s.length(); i ++) {
                while (rt < s.length()) {
                    if (cnt == num && cs[s[rt] - 'a'] == 0) break;
                    if (cs[s[rt] - 'a'] == 0) cnt ++, less_k ++;
                    cs[s[rt] - 'a'] ++;
                    if (cs[s[rt] - 'a'] == k) less_k --;
                    rt ++;
                }
                if (!less_k) res = max(res, rt - i);
                cs[s[i] - 'a'] --;
                if (cs[s[i] - 'a'] == 0) cnt --, less_k --;
                if (cs[s[i] - 'a'] == k - 1) less_k ++;
            }
        }
        return res;
    }
};