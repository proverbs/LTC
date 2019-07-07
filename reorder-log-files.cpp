class Solution {
public:
    static int letter_log(const string& s) {
        int sn = s.length();
        if (s[sn - 1] < 'a' || s[sn - 1] > 'z') return -1;
        else {
            int p = 0;
            while (s[p ++] != ' ');
            return p;
        }
    }
    
    static bool cmp(const string& a, const string& b) {
        // b is the former number, a is the later number
        // false means not to swap
        int ap = letter_log(a);
        int bp = letter_log(b);
        if (ap == -1 && bp == -1) return false;
        else if (ap == -1) return false;
        else if (bp == -1) return true;
        else {
            string sa = a.substr(ap);
            string sb = b.substr(bp);
            if (sa == sb) return a < b;
            return a.substr(ap) < b.substr(bp);
        }
    }
    
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(), logs.end(), cmp);
        return logs;
    }
};