// stack

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> v = split(path + "/");
        string res;
        for (int i = 0; i < v.size(); i ++) res += "/" + v[i];
        if (res.size() == 0) res += "/";
        return res;
    }
    
    vector<string> split(string p) {
        vector<string> res;
        string x;
        for (int i = 0; i < p.length(); i ++) {
            if (p[i] == '/') {
                if (!x.length() || x == ".") {
                    x = "";
                    continue;
                }
                if (x == "..") {
                    if (res.size()) res.pop_back();
                }
                else res.push_back(x);
                x = "";
            } else {
                x.push_back(p[i]);
            }
        }
        return res;
    }
};