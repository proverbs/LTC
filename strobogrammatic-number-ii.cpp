class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        return find(n, false);
    }
    
    vector<string> find(int n, bool zero) {
        vector<string> res;
        if (n == 0) {
            res.push_back("");
            return res;
        } else if (n == 1) {
            res.push_back("0");
            res.push_back("1");
            res.push_back("8");
        } else {
            vector<string> mid = find(n - 2, true);
            for (string &s : mid) {
                if (zero) res.push_back("0" + s + "0");
                res.push_back("1" + s + "1");
                res.push_back("8" + s + "8");
                res.push_back("6" + s + "9");
                res.push_back("9" + s + "6");
            }
        }
        return res;
    }
};