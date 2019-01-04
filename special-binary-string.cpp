// represent is as "mountains": https://leetcode.com/problems/special-binary-string/solution/

class Solution {
public:
    string makeLargestSpecial(string S) {
        int n = S.length();
        int h = n >> 1;
        for (int j = h; j >= 0; j --) { // greedy: from high to low, e.g. 111000-1101110000
            vector<int> st, ed;
            int dh = 0;
            for (int i = 0; i < n; i ++) {
                if (S[i] == '0') {
                    if (-- dh == j) ed.push_back(i);
                } else {
                    if (dh ++ == j) st.push_back(i);
                } 
            }
            
            int p = 0;
            while (p < st.size()) {
                vector<string> hs;
                string res = S.substr(0, st[p]);
                while (p < st.size() - 1) {
                    if (ed[p] == st[p + 1] - 1) hs.push_back(S.substr(st[p], ed[p] - st[p] + 1));
                    else break;
                    p ++;
                }
                hs.push_back(S.substr(st[p], ed[p] - st[p] + 1));
                p ++;
                
                if (hs.size() == 1) continue;
                
                sort(hs.begin(), hs.end());
                
                for (int i = hs.size() - 1; i >= 0; i --) res += hs[i];
                res += S.substr(ed[p - 1] + 1);
                S = res;
                // cout << res << endl;
            }
            
        }
        return S;
    }
};