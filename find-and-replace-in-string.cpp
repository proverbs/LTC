// sort can save space, but waste time
// space complexity: O(n*len)
// time complexity: O(n*len)
#include <map>

class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        unordered_map<int, string> mp;
        for (int i = 0; i < indexes.size(); i ++) {
            if (compare(S, sources[i], indexes[i])) {
                int len = sources[i].length();
                for (int j = 0; j < len; j ++) mp[indexes[i] + j] = "";
                mp[indexes[i]] = targets[i];
            } 
        }
        char a[110000];
        int cnt = 0;
        for (int i = 0; i < S.length(); i ++) {
            if (mp.count(i)) {
                // replaced by sources
                for (int j = 0; j < mp[i].length(); j ++) {
                    a[cnt ++] = mp[i][j];
                }
            } else {
                // not replaced
                a[cnt ++] = S[i];
            }
        }
        a[cnt] = '\0';
        return string(a);
    }
    
    bool compare(string &s1, string &s2, int x) {
        for (int i = 0; i < s2.length(); i ++) {
            if (x + i >= s1.length() || s1[x + i] != s2[i]) return false;
        }
        return true;
    }
};