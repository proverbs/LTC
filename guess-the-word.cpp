// because words are  generated randomly, there should be many pairs matching 0 letters 
// and much less pairs matching word.length()-1 letters.
// For a word, if the return value of guess() is 0, we cannot exclude any other words.
// So, we should select the word with least matching-0 pairs to guess to recuce the probability
// of getting 0 from guess().

/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        vector<bool> vis(wordlist.size(), false);
        while (true) {
            int max_val = -1;
            int idx = -1;
            for (int i = 0; i < wordlist.size(); i ++) {
                if (vis[i]) continue;
                int val = 0;
                for (int j = 0; j < wordlist.size(); j ++) {
                    if (i == j || vis[j]) continue;
                    int x = match(wordlist[i], wordlist[j]);
                    if (x) val ++;
                }
                if (val > max_val) {
                    max_val = val;
                    idx = i;
                }
            }
            
            int x = master.guess(wordlist[idx]);
            if (x == wordlist[0].length()) return;
            
            vis[idx] = true;
            if (x == -1) continue;
            for (int i = 0; i < wordlist.size(); i ++) {
                if (vis[i]) continue;
                int y = match(wordlist[i], wordlist[idx]);
                if (y != x) vis[i] = true;
            }
        }
    }
    
    int match(string &a, string &b) {
        int res = 0;
        for (int i = 0; i < a.length(); i ++) {
            res += (a[i] == b[i]);
        }
        return res;
    }
};