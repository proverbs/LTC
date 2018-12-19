class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        map<string, bool> addr;
        for (int i = 0; i < emails.size(); i ++) {
            string a = interpret(emails[i]);
            addr[a] = true;
        }
        return addr.size();
    }
    
    string interpret(string& x) {
        string res = "";
        int fg = 0;
        for (int i = 0; i < x.length(); i ++) {
            if (!fg) {
                if (x[i] == '+') fg = 1;
                else if (x[i] >= 'a' && x[i] <= 'z') res.push_back(x[i]); 
            } else if (fg == 1) {
                if (x[i] == '@') {
                    fg ++;
                    res.push_back(x[i]);
                }
            } else {
                res.push_back(x[i]);
            }
        }
        return res;
    }
};