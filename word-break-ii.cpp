// the same as word-break
// the only difference if you need to return all solutions
// dp + linked list to save the decisions(avoid MLE)

#include <unordered_map>

using namespace std;

struct LK {
    int num;
    LK *next;
    LK(int x) : num(x), next(NULL) {}
};

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> mp;
        int n = s.length();
        for (int i = 0; i < wordDict.size(); i ++) {
            mp[wordDict[i]] = true;
        }
        
        vector<bool> dp;
        vector<LK *> nxt;
        dp.resize(n + 1, false);
        nxt.resize(n + 1);
        for (int i = 0; i < n; i ++) nxt[i] = new LK(0);
        
        dp[n] = 1;
        for (int i = n - 1; i >= 0; i --) {
            string t = "";
            for (int j = i; j < n; j ++) {
                t.push_back(s[j]);
                if (dp[j + 1] && mp[t]) {
                    dp[i] = true;
                    LK* ad = new LK(j + 1);
                    ad->next = nxt[i]->next;
                    nxt[i]->next = ad;
                }
            }
        }
        vector<string> ans;
        dfs(0, ans, n, "", nxt, s);
        
        
        for (int x = 0; x < n; x ++)
            for (LK *p = nxt[x]->next, *q; p != NULL; p = p->next, free(q)) {
                q = p;
            }
        return ans;
    }
    
    void dfs(int x, vector<string> &ans, int n, string cur_str, vector<LK *> &nxt, string &s) {
        if (x == n) {
            ans.push_back(cur_str);
            return;
        }
        for (LK *p = nxt[x]->next; p != NULL; p = p->next) {
            if (x == 0) dfs(p->num, ans, n, s.substr(x, p->num - x), nxt, s);
            else dfs(p->num, ans, n, cur_str + " " + s.substr(x, p->num - x), nxt, s);
        }
    }
};