/*trie*/

#include <iostream>
#include <vector>

using namespace std;

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        t = new vector<NODE>;
        t->push_back(NODE());
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int idx = 0;
        for (int i = 0; i < word.length(); i ++) {
            int z = (*t)[idx].son[word[i] - 'a'];
            if (z == -1) {
                t->push_back(NODE());
                (*t)[idx].son[word[i] - 'a'] = z = t->size() - 1;
            }
            idx = z;
        }
        (*t)[idx].fg = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int idx = 0;
        for (int i = 0; i < word.length(); i ++) {
            int z = (*t)[idx].son[word[i] - 'a'];
            if (z == -1) return false;
            idx = z;
        }
        return (*t)[idx].fg;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int idx = 0;
        for (int i = 0; i < prefix.length(); i ++) {
            int z = (*t)[idx].son[prefix[i] - 'a'];
            if (z == -1) return false;
            idx = z;
        }
        return true;
    }
private:
    struct NODE {
        int son[26];
        bool fg;
        NODE() {
            fg = 0;
            for (int i = 0; i < 26; i ++) son[i] = -1;
        }
    };
    vector<NODE>* t;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */

int main() {
    Trie* obj = new Trie();
    obj->insert(word);
    bool param_2 = obj.search(word);
    bool param_3 = obj.startsWith(prefix);
}