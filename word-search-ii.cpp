// search the trie and board at the same time
// in the worst case, it is the same as straightforward dfs

class Solution {
public:
    struct TrieNode {
        int son[26];
        int fg;
        string s;
        TrieNode() {
            fg = 0;
            for (int i = 0; i < 26; i ++) son[i] = -1;
        }
    };
    
    vector<TrieNode> t;
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    vector<vector<bool>> vis;

    set<string> res;
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        t.clear();
        t.push_back(TrieNode());

        vis.resize(board.size(), vector<bool>(board[0].size(), false));
        
        res.clear();

        for (int i = 0; i < words.size(); i ++) {
            insert(words[i]);
        }
        for (int i = 0; i < board.size(); i ++) {
            for (int j = 0; j < board[i].size(); j ++) {
                int k = board[i][j]  - 'a';
                if (t[0].son[k] != -1) dfs_trie(t[0].son[k], i, j, board);
            }
        }
        set<string>::iterator it;
        vector<string> r;
        for (it = res.begin(); it != res.end(); it ++) r.push_back(*it);
        return r;
    }
    
    void insert(string &s) {
        int now = 0;
        for (int i = 0; i < s.length(); i ++) {
            int c = s[i] - 'a';
            if (t[now].son[c] == -1) {
                t.push_back(TrieNode());
                t[now].son[c] = t.size() - 1;
            }
            now = t[now].son[c];
        }
        t[now].fg = 1;
        t[now].s = s;
    }
    
    void dfs_trie(int r, int x, int y, vector<vector<char>>& board) {

        if (t[r].fg) res.insert(t[r].s);

        vis[x][y] = true;
        for (int j = 0; j < 4; j ++) {
            int nx = x + dx[j];
            int ny = y + dy[j];
            if (nx >= board.size() || nx < 0) continue;
            if (ny >= board[0].size() || ny < 0) continue;

            int k = board[nx][ny] - 'a';
            if (!vis[nx][ny] && t[r].son[k] != -1) {
                dfs_trie(t[r].son[k], nx, ny, board);
            }
        }
        vis[x][y] = false;
    }
};