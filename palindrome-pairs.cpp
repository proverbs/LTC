// typical: 2 tries
// time complexity: O(n*len)
// space complexity: O(n*len)

class Solution {
private:
    struct TrieNode {
        int son[26];
        int flag;
        TrieNode() {
            for (int i = 0; i < 26; i ++) son[i] = -1;
            flag = -1;
        }
    };
    vector<TrieNode> t;

public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        set<pair<int, int>> pr;
        
        // normal trie: words[x] + words[i], words[i] is longer(or equal length)
        t.clear(); 
        t.push_back(TrieNode());
        for (int i = 0; i < words.size(); i ++) {
            insert(words[i], i);
        }
        for (int i = 0; i < words.size(); i ++) {
            reverse(words[i].begin(), words[i].end());
            vector<int> art = find(words[i]);
            for (int j = 0; j < art.size(); j ++) {
                int rt = art[j];
                if (rt == i) continue;
                if (is_palindrome(words[i], words[rt].length())) {
                    pr.insert(make_pair(rt, i));
                }
            }
        }
        
        // reverse trie, words[i] + words[x], words[i] is longer
        t.clear(); 
        t.push_back(TrieNode());
        for (int i = 0; i < words.size(); i ++) {
            insert(words[i], i);
        }
        for (int i = 0; i < words.size(); i ++) {
            reverse(words[i].begin(), words[i].end());
            vector<int> art = find(words[i]);
            for (int j = 0; j < art.size(); j ++) {
                int rt = art[j];
                if (rt == i) continue;
                if (words[i].length() != words[rt].length() && 
                    is_palindrome(words[i], words[rt].length())) {
                    pr.insert(make_pair(i, rt));
                }
            }
        }
        
        // get
        for (set<pair<int, int>>::iterator it = pr.begin(); it != pr.end(); it ++) {
            vector<int> tmp;
            tmp.push_back(it->first);
            tmp.push_back(it->second);
            res.push_back(tmp);
        }
        
        return res;
    }
    
    void insert(string &s, int idx) {
        int now = 0;
        for (int i = 0; i < s.length(); i ++) {
            if (t[now].son[s[i] - 'a'] == -1) {
                t.push_back(TrieNode());
                t[now].son[s[i] - 'a'] = t.size() - 1;
            }
            now = t[now].son[s[i] - 'a'];
        }
        t[now].flag = idx;
    }
    
    vector<int> find(string &s) {
        vector<int> arr;
        int now = 0;
        if (t[now].flag != -1) arr.push_back(t[now].flag);
        for (int i = 0; i < s.length(); i ++) {
            if (t[now].son[s[i] - 'a'] == -1) {
                break;
            }
            now = t[now].son[s[i] - 'a'];
            if (t[now].flag != -1) arr.push_back(t[now].flag);
        }
        return arr;
    }
    
    bool is_palindrome(string &s, int lt) {
        int rt = s.length() - 1;
        while (lt < rt) {
            if (s[lt] != s[rt]) return false;
            lt ++;
            rt --;
        }
        return true;
    }
};