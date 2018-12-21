// similar to high-precision calculation

class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string res = "";
        char jin = '0';
        int len = max(a.length(), b.length());
        for (int i = 0; i < len; i ++) {
            char c = '0';
            if (i < a.length()) c += a[i] - '0';
            if (i < b.length()) c += b[i] - '0';
            c = jin - '0' + c;
            if (c == '3') {
              jin = '1';
                res = "1" + res;
            } else if (c == '2') {
                jin = '1';
                res = "0"  + res;
            } else {
                jin = '0';
                if (c == '0') res = "0" + res;
                else res = "1" + res;
            }
        }
        if (jin == '1') res = "1" + res;
        return res;
    }
};