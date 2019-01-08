class Solution {
public:
    unordered_map<int, int> id;
    int idn, res;
    vector<int> out;
    int minTransfers(vector<vector<int>>& transactions) {
        id.clear();
        idn = 0;
        for (vector<int>& t : transactions) {
            if (!id.count(t[0])) id[t[0]] = idn ++;
            if (!id.count(t[1])) id[t[1]] = idn ++;
        }
        out.clear();
        out.resize(idn, 0);
        for (vector<int>& t : transactions) {
            out[id[t[0]]] += t[2];
            out[id[t[1]]] -= t[2];
        }
        res = 9999999;
        dfs(0, 0);
        return res;
    }
    
    void dfs(int x, int cs) {
        if (x >= out.size()) {
            res = min(res, cs);
            return;
        }
        if (out[x] == 0) dfs(x + 1, cs);
        else {
            for (int i = x + 1; i < out.size(); i ++) {
                if (out[i] * out[x] >= 0) continue;
                out[i] += out[x]; // brilliant! use i to replace x to pay or get paied
                dfs(x + 1, cs + 1);
                out[i] -= out[x];
            }
        }
    }
};