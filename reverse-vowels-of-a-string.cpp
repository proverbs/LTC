class Solution {
public:
    string reverseVowels(string s) {
        vector<char> t;
        set<char> st({'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'});
        for (char c: s) {
            if (st.count(c)) t.push_back(c);
        }
        for (int i = s.length() - 1, j = 0; i >= 0; i --) {
            if (st.count(s[i])) s[i] = t[j ++];
        }
        return s;
    }
};