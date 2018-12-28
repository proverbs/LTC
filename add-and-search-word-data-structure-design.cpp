// dfs on trie

class WordDictionary {
public:
    struct TrieNode {
        int son[26];
        bool fg;
        TrieNode() : fg(false) {
            for (int i = 0; i < 26; i ++) son[i] = -1;
        }
    };
    vector<TrieNode> t;
    /** Initialize your data structure here. */
    WordDictionary() {
        t.push_back(TrieNode());
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        int now = 0;
        for (int i = 0; i < word.length(); i ++) {
            int c = word[i] -'a';
            if (t[now].son[c] == -1) t.push_back(TrieNode()), t[now].son[c] = t.size() -1;
            now = t[now].son[c];
        }
        t[now].fg = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return dfs(word, 0, 0);
    }
    
    bool dfs(string &s, int idx, int now) {
        if (idx == s.length()) return t[now].fg;

        if (s[idx] == '.') {
            for (int j = 0; j < 26; j ++)
                if (~t[now].son[j] && dfs(s, idx + 1, t[now].son[j])) return true;
        } else {
            int c = s[idx] -'a';
            if (~t[now].son[c] && dfs(s, idx + 1, t[now].son[c])) return true;
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */