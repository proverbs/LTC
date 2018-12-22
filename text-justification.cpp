class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        for (int i = 0; i < words.size(); i ++) {
            int lt = i;
            int len = 0;
            while (lt < words.size() && words[lt].length() + len + (lt - i) <= maxWidth) {
                len += words[lt].length();
                lt ++;
            }
            
            string s;
            if (lt == words.size()) {
                for (int j = i; j < lt; j ++) {
                    s = s + words[j];
                    if (j != lt - 1) s.push_back(' ');
                }
                while (s.length() < maxWidth) s.push_back(' ');
            } else {
                int sumsp = maxWidth - len;
                int sp;
                if (lt - i - 1) {
                    sp = sumsp / (lt - i - 1);
                    if (sumsp % (lt - i - 1)) sp ++;
                }
                else sp = sumsp;
                
                for (int j = i; j < lt; j ++) {
                    s = s + words[j];
                    if (sumsp) {
                        for (int k = 0; k < sp; k ++) {
                            s.push_back(' ');
                        }
                    }
                    
                    sumsp -= sp;
                    if (j + 2 != lt && sumsp % (lt - j - 2) == 0) sp = sumsp / (lt - j - 2);
                }
            }
            res.push_back(s);
            
            i = lt - 1;
        }
        
        return res;
    }
};