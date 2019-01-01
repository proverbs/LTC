unordered_map<char, int> cs;

class Solution {
public:
    static bool cmp(const char &a, const char &b) {
        if (cs[a] == cs[b]) return a < b;
        return cs[a] > cs[b]; // cannot use with '='
    }
    
    string frequencySort(string s) {
        cs.clear();
        for (char c : s) {
            if (cs.count(c)) cs[c] ++;
            else cs[c] = 1;
        }
        
        sort(s.begin(), s.end(), cmp);
        return s;
    }
};