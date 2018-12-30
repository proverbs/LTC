// O(n), greedy

class Solution {
public:
    string removeDuplicateLetters(string s) {
        deque<int> idx[26];
        vector<bool> vis(26, true);
        for (int i = 0; i < s.length(); i ++) {
            idx[s[i] - 'a'].push_back(i);
            vis[s[i] - 'a'] = false;
        }
        int len = 0;
        for (int i = 0; i < 26; i ++)
            if (!vis[i]) len ++;
        
        string res;
        for (int i = 0; i < len; i ++) { // the i-th position
            for (int j = 0; j < 26; j ++) { // which letter, greedy
                if (vis[j]) continue;
                for (int x : idx[j]) {
                    bool fg = true;
                    for (int k = 0; k < 26; k ++)
                        if (!vis[k] && k != j && idx[k].back() < x) {
                            fg = false;
                            break;
                        }
                    if (!fg) continue;
                    
                    vis[j] = true;
                    for (int k = 0; k < 26; k ++)
                        if (!vis[k]) {
                            while (idx[k].front() < x) idx[k].pop_front();
                        }
                    
                    res.push_back('a' + j);
                    break;
                }
                if (vis[j]) break;
            }
        }
        return res;
    }
};