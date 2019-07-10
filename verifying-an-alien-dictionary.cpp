class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> w;
        for (int i = 0; i < 26; i ++) w[order[i]] = i;
        for (int i = 1; i < words.size(); i ++) {
            if (!cmp(words[i - 1], words[i], w)) return false; 
        }
        return true;
    }
    
    bool cmp(const string& a, const string& b, unordered_map<char, int>& w) {
        int mlen = min(a.length(), b.length());
        for (int i = 0; i < mlen; i ++) {
            if (w[a[i]] < w[b[i]]) return true;
            if (w[a[i]] > w[b[i]]) return false;
        }
        return mlen == a.length();
    }
};