// classic: recursively insert string

class AutocompleteSystem {
public:
    struct PX {
        int cs;
        string s;
        PX() {}
        PX(int cs, string s) {
            this->cs = cs;
            this->s = s;
        }
    };
    
    struct TrieNode {
        int son[27];
        int cs;
        PX top3[4];
        int n;
        string s;
        TrieNode() {
            for (int i = 0; i < 27; i ++) {
                son[i] = -1;
            }
            n = 0;
            cs = 0;
        }
    };
    vector<TrieNode> t;
    
    int cur;
    string curstr;
    
    AutocompleteSystem(vector<string> sentences, vector<int> times) {
        t.clear();
        t.push_back(TrieNode());
        for (int i = 0; i < sentences.size(); i ++) {
            insert(0, sentences[i], 0, times[i]);
        }
        cur = 0;
        curstr = "";
    }
    
    static bool cmp(const PX &a, const PX &b) {
        if (a.cs == b.cs) return a.s < b.s;
        return a.cs > b.cs;
    }

    void insert(int now, string &s, int idx, int tm) {
        // update top3
        bool fg = false;
        for (int i = 0; i < t[now].n; i ++) {
            if (t[now].top3[i].s == s) {
                t[now].top3[i].cs = tm;
                sort(t[now].top3, t[now].top3 + t[now].n, cmp);
                fg = true;
                break;
            }
        }
        if (!fg) {
            t[now].top3[t[now].n ++] = PX(tm, s);
            sort(t[now].top3, t[now].top3 + t[now].n, cmp);
            if (t[now].n == 4) t[now].n --;
        }


        if (idx < s.length()) {
            int c = s[idx] - 'a' + 1;
            if (s[idx] == ' ') c = 0;
            
            // insert node
            if (t[now].son[c] == -1) {
                t.push_back(TrieNode());
                t[now].son[c] = t.size() - 1;
            }
            insert(t[now].son[c], s, idx + 1, tm);
        } else {
            t[now].cs = tm;
            t[now].s = s;
        }
    }
    
    vector<string> input(char c) {
        vector<string> res;
        // update
        if (c == '#') {
            insert(0, curstr, 0, t[cur].cs + 1);
            curstr = "";
            cur = 0;
            return res;
        } else {
            curstr.push_back(c);
        }
        
        int cz = c - 'a' + 1;
        if (c == ' ') cz = 0;
        
        // insert node
        if (t[cur].son[cz] == -1) {
            t.push_back(TrieNode());
            t[cur].son[cz] = t.size() - 1;
        }
        
        cur = t[cur].son[cz];
        for (int i = 0; i < t[cur].n; i ++) {
            res.push_back(t[cur].top3[i].s);
            // cout << t[cur].top3[i].s << " " << t[cur].top3[i].cs << endl;
        }
        return res;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj.input(c);
 */