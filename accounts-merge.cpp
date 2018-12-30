// union find

// cannot merge in one pass, for example:
// [["David","David0@m.co","David1@m.co"],["David","David3@m.co","David4@m.co"],["David","David4@m.co","David5@m.co"],["David","David2@m.co","David3@m.co"],["David","David1@m.co","David2@m.co"]]

class Solution {
public:
    vector<int> fa;
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> idx;
        vector<vector<string>> res;
        unordered_map<int, set<string>> mes;
        unordered_map<int, string> names;
        
        for (int i = 0; i < accounts.size(); i ++) fa.push_back(i);
        
        for (int i = 0; i < accounts.size(); i ++) {
            vector<string>& ai = accounts[i];
            for (int j = 1; j < ai.size(); j ++) {
                if (idx.count(ai[j])) {
                    int fx = findfa(idx[ai[j]]);
                    int fy = findfa(i);
                    if (fx != fy) fa[fx] = fy;
                } else idx[ai[j]] = i;
            }
        }
        
        for (int i = 0; i < accounts.size(); i ++) cout << i << "  " << findfa(i) << endl;
        
        for (int i = 0; i < accounts.size(); i ++) {
            vector<string>& ai = accounts[i];
            int index = findfa(i);
            if (!mes.count(index)) {
                mes[index] = set<string>();
                names[index] = ai[0];
            }
            for (int j = 1; j < ai.size(); j ++)
                mes[index].insert(ai[j]);
        }
        
        for (pair<int, set<string>> r : mes) {
            vector<string> rx;
            rx.push_back(names[r.first]);
            for (string s : r.second)
                rx.push_back(s);
            res.emplace_back(rx);
        }
        return res;
    }
    
    int findfa(int x) {
        if (x != fa[x]) fa[x] = findfa(fa[x]);
        return fa[x];
    }
};