class Solution {
public:
    int p;
    string mostCommonWord(string paragraph, vector<string>& banned) {
        p = 0;
        unordered_map<string, int> cs;
        for (int i = 0; i < banned.size(); i ++) {
            cs[banned[i]] = -999999;
        }
        while (true) {
            string s = read_word(paragraph);
            if (s.length() == 0) break;
            if (!cs.count(s)) cs[s] = 0;
            cs[s] ++;
        }
        string res = "";
        int max_cs = 0;
        unordered_map<string, int>::iterator it;
        for (it = cs.begin(); it != cs.end(); it ++) {
            if (it->second > max_cs) {
                max_cs = it->second;
                res = it->first;
            }
        }
        return res;
    }
    
    string read_word(string &pa) {
        string res = "";
        while (p < pa.length() && !is_letter(pa[p])) p ++;
        while (p < pa.length() && is_letter(pa[p])) {
            if (pa[p] < 'a') res.push_back(pa[p] - 'A' + 'a');
            else res.push_back(pa[p]);
            p ++;
        }
        return res;
    }
    
    bool is_letter(char x) {
        if (x >= 'a' && x <= 'z') return true;
        if (x >= 'A' && x <= 'Z') return true;
        return false;
    }
};