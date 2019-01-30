// note: need two maps

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for (string& wd: words) {
            if (wd.length() != pattern.length()) continue;
            unordered_map<char, char> pa2wd, wd2pa;
            int i;
            for (i = 0; i < wd.length(); i ++) {
                if (!wd2pa.count(wd[i])) {
                    if (pa2wd.count(pattern[i])) break;
                    else {
                        pa2wd[pattern[i]] = wd[i];
                        wd2pa[wd[i]] = pattern[i];
                    }
                } else if (wd2pa[wd[i]] != pattern[i]) {
                    break;
                }
            }
            if (i == wd.length()) res.push_back(wd);
        }
        return res;
    }
};