// O(n^2) dfs

class Solution {
public:
    map<string, int> ct;
    string countOfAtoms(string formula) {
        if (formula.length() == 0) return "";
        ct.clear();
        dfs(formula, 0, formula.length() - 1, 1);
        string res;
        for (auto& pr : ct) {
            res += pr.first;
            if (pr.second != 1) res += to_string(pr.second);
        }
        return res;
    }
    
    void dfs(string& f, int lt, int rt, int scale) {
        stack<int> idx;
        string t = "";
        int num = 0;
        for (int i = lt; i <= rt; i ++) {
            if (f[i] == '(') {
                if (t.length()) {
                    if (!num) num = 1;
                    if (ct.count(t)) ct[t] += num * scale;
                    else ct[t] = num *scale;
                }
                idx.push(i);
                t = "";
                num = 0;
            } else if (f[i] == ')') {
                int x = idx.top();
                idx.pop();
                if (!idx.empty()) continue;
                int z = 0, p = i + 1;
                while (p <= rt && f[p] >= '0' && f[p] <= '9') 
                    z = z * 10 + f[p ++] - '0';
                if (!z) z = 1;
                dfs(f, x + 1, i - 1, scale * z);
            } else {
                if (!idx.empty()) continue;
                if (f[i] >= 'A' && f[i] <= 'Z') {
                    if (t.length()) {
                        if (!num) num = 1;
                        if (ct.count(t)) ct[t] += num * scale;
                        else ct[t] = num *scale;
                    }
                    t = "";
                    t.push_back(f[i]);
                    num = 0;
                } else if (f[i] >= 'a' && f[i] <= 'z') {
                    t.push_back(f[i]);
                } else if (f[i] >= '0' && f[i] <= '9'){
                    num = num * 10 + f[i] - '0';
                } 
            }
        }
        if (t.length()) {
            if (!num) num = 1;
            if (ct.count(t)) ct[t] += num * scale;
            else ct[t] = num *scale;
        }
    } 
};