// double the string for shift operation
// kmp to find substring

class Solution {
public:
    bool rotateString(string A, string B) {
        if (A.length() != B.length()) return false;
        if (A.length() == 0) return true;
        string a = A + A;
        return kmp(a, B) != -1;
    }
    
    int kmp(string& a, string& b) {
        int len = 0;
        int n = b.length();
        vector<int> p(n, 0);
        for (int i = 1; i < n; i ++) {
            while (len && b[len] != b[i]) len = p[len - 1];
            if (b[len] == b[i]) len ++;
            p[i] = len;
        }
        len = 0;
        for (int i = 0; i < a.length(); i ++) {
            while (len && b[len] != a[i]) len = p[len - 1];
            if (b[len] == a[i]) len ++;
            if (len == n) return i - len + 1;
        }
        return -1;
    }
};