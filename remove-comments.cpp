class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> res;
        bool fg = false;
        char lst = ' ';
        string s = "";
        for (int i = 0; i < source.size(); i ++) {
            if (!fg) s = "";
            for (int j = 0; j < source[i].size(); j ++) {
                if (source[i][j] == '/' && s.back() == '/') {
                    s.pop_back();
                    lst = ' ';
                    break;
                } else if (source[i][j] == '*' && s.back() == '/') {
                    s.pop_back();
                    fg = true;
                    lst = ' ';
                } else if (source[i][j] == '/' && lst == '*' && fg) {
                    fg = false;
                    lst = source[i][j];
                } else if (!fg) {
                    s.push_back(source[i][j]);
                    lst = source[i][j];
                } else {
                    lst = source[i][j];
                }
            }
            if (!fg && s.length()) res.push_back(s);
            
            cout << i << endl;
        }
        return res;
    }
};