class Solution {
public:
    bool isIsomorphic(string s, string t) {
        return test(s, t) && test(t, s);
    }
    
    bool test(string s, string t) {
        map<char, char> mp;
        for (int i = 0; i < s.length(); i ++) mp[s[i]] = t[i];
        for (int i = 0; i < s.length(); i ++) s[i] = mp[s[i]];
        return s == t;
    }
};