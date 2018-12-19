class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        int len = 0;
        for (int i = 0; i < S.length(); i ++) {
            if (S[i] != '-') len ++;
        }
        int y = len % K;
        string res = "";
        int tlen = 0;
        for (int i = 0; i < S.length(); i ++) {
            if (S[i] != '-') {
                if (tlen == K) {
                    res.push_back('-');
                    tlen = 0;
                }
                if (S[i] >= 'a' && S[i] <= 'z') res.push_back(S[i] + 'A' - 'a');
                else res.push_back(S[i]);
                tlen ++;
            }
            if (y && res.length() == y) {
                tlen = K;
            }
        }
        return res;
    }
};