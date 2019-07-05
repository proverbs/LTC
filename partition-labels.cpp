class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> res;
        vector<int> rt(26, 0);
        vector<int> lt(26, 0);
        for (char c: S) {
            rt[c - 'a'] ++;
        }
        
        int last = 0;
        for (int i = 0; i < S.length(); i ++) {
            bool jg = true;
            for (int j = 0; j < 26; j ++) {
                if (lt[j] && rt[j]) {
                    jg = false;
                    break;
                }
            }
            if (jg && last != i) {
                res.push_back(i - last);
                lt.clear();
                lt.resize(26, 0);
                last = i --;
            } else {
                lt[S[i] - 'a'] ++;
                rt[S[i] - 'a'] --;
            }
        }
        res.push_back(S.length() - last);

        return res;
    }
};