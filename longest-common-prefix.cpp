/*暴力*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = 0;
        bool fg = true;
        if (strs.size() == 0) return "";
        while (1) {
            for (int i = 0; i < strs.size(); i ++) {
                if (strs[i].length() == len || strs[i][len] != strs[0][len]) {
                    fg = false;
                    break;
                }
            }
            if (fg) len ++;
            else break;
        }
        return strs[0].substr(0, len);
    }
};