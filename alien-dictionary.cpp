// topological sort

class Solution {
public:
    vector<int> indu;
    vector<int> vis;
    vector<vector<int>> edg;
    string alienOrder(vector<string>& words) {
        indu.resize(26, 0);
        vis.resize(26, 0);
        edg.resize(26, vector<int>());
        for (int i = 0; i < 26; i ++) edg[i].resize(26, 0);
        
        for (int i = 0; i < words.size(); i ++) {
            for (int j = 0; j < words[i].length(); j ++) {
                vis[words[i][j] - 'a'] = 1;
            }
        }
        
        for (int i = 0; i < words.size() - 1; i ++) {
            string w1 = words[i];
            string w2 = words[i + 1];
            int ll = 0;
            while (ll < w1.length() && ll < w2.length()) {
                if (w1[ll] != w2[ll]) {
                    add(w1[ll] - 'a', w2[ll] - 'a');
                    break;
                }
                ll ++;
            }
        }
        
        return top_sort();
    }
    
    void add(int u, int v) {
        // printf("%c %c\n", u + 'a', v + 'a');
        if (!edg[u][v]) {
            edg[u][v] = 1;
            indu[v] ++;
        }
    }
    
    string top_sort() {
        string res = "";
        queue<int> q;
        for (int i = 0; i < 26; i ++) {
            if (vis[i] && indu[i] == 0) q.push(i);
        }
        
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            res.push_back('a' + x);
            for (int i = 0; i < 26; i ++) {
                if (edg[x][i]) {
                    if (-- indu[i] == 0) q.push(i);
                }
            }
        }
        for (int i = 0; i < 26; i ++) {
            if (indu[i] != 0) return "";
        }
        return res;
    }
    
};