class Solution {
public:
    unordered_map<string, int> mp;
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        mp.clear();
        for (int i = 0; i < cpdomains.size(); i ++) {
            pair<string, int> pr = interpret(cpdomains[i]);
            dfs(pr.first, pr.second);
        }
        unordered_map<string, int>::iterator it;
        char cx[200];
        vector<string> res;
        for (it = mp.begin(); it != mp.end(); it ++) {
            sprintf(cx, "%d %s", it->second, it->first.c_str());
            res.push_back(string(cx));
        }
        return res;
    }
    
    pair<string, int> interpret(string &s) {
        char cx[100];
        int x;
        sscanf(s.c_str(), "%d %s", &x, cx);
        return make_pair(string(cx), x);
    }
    
    void dfs(string s, int x) {
        if (!mp.count(s)) mp[s] = 0;
        mp[s] += x;
        for (int i = 0; i < s.length(); i ++) {
            if (s[i] == '.') {
                dfs(s.substr(i + 1), x);
                break;
            }
        }
    }
};