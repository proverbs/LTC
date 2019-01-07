class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int idx = -999999;
        int res = 999999;
        for (int i = 0; i < words.size(); i ++) {
            if (words[i] == word1) idx = i;
            else if (words[i] == word2) res = min(res, i - idx);
        }
        
        idx = 9999999;
        for (int i = words.size() - 1; i >= 0; i --) {
            if (words[i] == word1) idx = i;
            else if (words[i] == word2) res = min(res, idx - i);
        }
        
        return res;
    }
};