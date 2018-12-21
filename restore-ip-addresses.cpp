// brute force

class Solution {
public:
    vector<string> res;
    
    vector<string> restoreIpAddresses(string s) {
        res.clear();
        dfs(s, 0, 4, "");
        return res;
    }
    
    void dfs(string& s, int b, int r, string zs) {
        // cout << zs << endl;
        if (!r) {
            if (b == s.length()) res.push_back(zs.substr(1));
            return;
        }
        
        int z = 0;
        for (int i = 0; i < 3 && b + i < s.length(); i ++) {
            z = z * 10 + s[b + i] - '0';
            if (z >= 0 && z < 256) dfs(s, b + i + 1, r - 1, zs + "." + s.substr(b, i + 1));
            if (z == 0) break; 
        }
    }
};