class Solution {
public:
    vector<vector<string> > partition(string s) {
        vector<vector<string> > res;
        vector<string> ts;
        search(s, ts, res); // kmp needed?
        return res;
    }
    
    void search(string s, vector<string> &ts, vector<vector<string> > &res) {
        if (s.length() == 0) {
            res.push_back(ts);
            return;
        }
        for (int i = 0; i < s.length(); i ++) {
            if (is_palindrome(s, i)) {
                ts.push_back(s.substr(0, i + 1));
                search(s.substr(i + 1), ts, res);
                ts.pop_back();
            }
        }
    }
    
    bool is_palindrome(string &s, int idx) {
        int lt = 0;
        while (lt <= idx) {
            if (s[lt] != s[idx]) return false;
            lt ++;
            idx --;
        }
        return true;
    }
};

