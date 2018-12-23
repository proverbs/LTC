class Solution {
public:
    bool backspaceCompare(string S, string T) {
        return cv(S) == cv(T);
    }
    
    string cv(string S) {
        string s;
        for (int i = 0; i < S.length(); i ++) {
            if (S[i] == '#') {
                if (s.length()) s.pop_back();
            } else {
                s.push_back(S[i]);
            }
        }
        return s;
    }
};