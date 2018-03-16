/*scan*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        map<char, int> mp, mt;
        for (char i = 'a'; i <= 'z'; i ++) mp[i] = mt[i] = 0;
        for (int i = 0; i < p.length(); i ++) mp[p[i]] ++;
        int lt = 0;
        vector<int> res;
        for (int i = 0; i <= s.length(); i ++) {
            if (i - lt < p.length()) {
                mt[s[i]] ++;
            } else {
                if (check(mp, mt)) res.push_back(lt);
                mt[s[lt ++]] --;
                mt[s[i]] ++;
            }
        }
        return res;
    }

    bool check(map<char, int>& mp, map<char, int>& mt) {
        for (char i = 'a'; i <= 'z'; i ++)
            if (mt[i] != mp[i]) return false;
        return true;
    }
};