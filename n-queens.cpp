class Solution {
public:
    vector<vector<string>> res;
    vector<string> state;
    vector<pair<int, int>> pos;
    int sz;
    
    vector<vector<string>> solveNQueens(int n) {
        string t;
        for (int i = 0; i < n; i ++) t.push_back('.');
        for (int i = 0; i < n; i ++) state.push_back(t);
        sz = n;
        dfs(n);
        return res;
    }
    
    void dfs(int n) {
        if (!n) res.push_back(state);
        else {
            for (int i = 0; i < sz; i ++) {
                if (check(sz - n, i)) {
                    pos.push_back(make_pair(sz - n, i));
                    state[sz - n][i] = 'Q';
                    dfs(n - 1);
                    state[sz - n][i] = '.';
                    pos.pop_back();
                }
            }
        }
    }
    
    bool check(int x, int y) {
        for (int i = 0; i < pos.size(); i ++) {
            if (x == pos[i].first) return false;
            if (y == pos[i].second) return false;
            if (x + y == pos[i].first + pos[i].second) return false;
            if (x - pos[i].first == y - pos[i].second) return false;
        }
        return true;
    }
};