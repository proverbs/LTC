// next letter pointer
// O(26s_len + words_len * word_len)

class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        int pos[26];
        for (int i = 0; i < 26; i ++) {
            pos[i] = S.length();
        }
        int jp[S.length()][26];
        for (int i = S.length() - 1; i >= 0; i --) {
            for (int j = 0; j < 26; j ++) {
                jp[i][j] = pos[j];
            }
            if (i != 0) pos[S[i] - 'a'] = i;
        }
        
        int res = 0;
        for (int i = 0; i < words.size(); i ++) {
            int x;
            if (words[i][0] == S[0]) x = 0;
            else x = pos[words[i][0] - 'a'];
            if (x == S.length()) continue;
            int len = 1;
            while (len < words[i].length() && jp[x][words[i][len] - 'a'] != (int)S.length()) {
                x = jp[x][words[i][len ++] - 'a'];
            }
            if (len == words[i].length()) res ++;
        }
        return res;
    }
};