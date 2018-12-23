// find the first larger palindromic number
// find the first less palindromic number

class Solution {
public:
    string nearestPalindromic(string n) {
        if (n == "0") return "1";
        string a = largerPalindromic(n, 0);
        string b = lessPalindromic(n, 0);
        long long la, lb, ln;
        sscanf(a.c_str(), "%lld", &la);
        sscanf(b.c_str(), "%lld", &lb);
        sscanf(n.c_str(), "%lld", &ln);
        if (la - ln < ln - lb) return a;
        return b;
    }
    
    string lessPalindromic(string n, int dt) { // dt: strict?
        int len = n.length();
        if (len == 1) {
            if (dt == 0) n[0] -= 1;
            return n;
        } else {
            if (len & 1) {
                // odd
                if (cmp(n, len / 2 - 1, len / 2 + 1) + dt <= -1) {
                    string t = n.substr(0, len / 2);
                    reverse(t.begin(), t.end());
                    return n.substr(0, len / 2 + 1) + t;
                } else {
                    string t = n.substr(0, len / 2 + 1);
                    t = subtract(t);
                    for (int i = 0; i < len / 2; i ++) {
                        t.push_back('9');
                    }
                    reverse(t.begin(), t.end());
                    while (t.back() == '0') t.pop_back();
                    reverse(t.begin(), t.end());
                    return lessPalindromic(t, -1);
                }
            } else {
                // even
                if (cmp(n, len / 2 - 1, len / 2) + dt <= -1) {
                    string t = n.substr(0, len / 2);
                    reverse(t.begin(), t.end());
                    return n.substr(0, len / 2) + t;
                } else {
                    string t = n.substr(0, len / 2);
                    t = subtract(t);
                    for (int i = 0; i < len / 2; i ++) {
                        t.push_back('9');
                    }
                    reverse(t.begin(), t.end());
                    while (t.back() == '0') t.pop_back();
                    reverse(t.begin(), t.end());
                    return lessPalindromic(t, -1);
                }
            }
        }
    }
    
    string largerPalindromic(string n, int dt) {
        int len = n.length();
        if (len & 1) {
            // odd
            if (cmp(n, len / 2 - 1, len / 2 + 1) + dt >= 1) {
                string t = n.substr(0, len / 2);
                reverse(t.begin(), t.end());
                return n.substr(0, len / 2 + 1) + t;
            } else {
                string t = n.substr(0, len / 2 + 1);
                t = add(t);
                for (int i = 0; i < len / 2; i ++) {
                    t.push_back('0');
                }
                reverse(t.begin(), t.end());
                while (t.back() == '0') t.pop_back();
                reverse(t.begin(), t.end());
                return largerPalindromic(t, 1);
            }
        } else {
            // even
            if (cmp(n, len / 2 - 1, len / 2) + dt >= 1) {
                string t = n.substr(0, len / 2);
                reverse(t.begin(), t.end());
                return n.substr(0, len / 2) + t;
            } else {
                string t = n.substr(0, len / 2);
                t = add(t);
                for (int i = 0; i < len / 2; i ++) {
                    t.push_back('0');
                }
                reverse(t.begin(), t.end());
                while (t.back() == '0') t.pop_back();
                reverse(t.begin(), t.end());
                return largerPalindromic(t, 1);
            }
        }
    }
    
    int cmp(string s, int la, int lb) {
        while (la >= 0 && s[la] == s[lb]) la --, lb ++;
        
        if (la < 0) return 0;
        else if (s[la] < s[lb]) return -1;
        else return 1;
    }
    
    string subtract(string s) {
        bool fg = true;
        for (int i = s.length() - 1; i >= 0; i --) {
            if (fg) {
                if (s[i] == '0') s[i] = '9';
                else s[i] -= 1, fg = false;
            }
        }
        return s;
    }
    
    string add(string s) {
        bool fg = true;
        for (int i = s.length() - 1; i >= 0; i --) {
            if (fg) {
                if (s[i] == '9') s[i] = '0';
                else s[i] += 1, fg = false;
            }
        }
        if (fg) s = "1" + s;
        return s;
    }
};