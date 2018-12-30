// n sliding windows, O(n*length)

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (words.size() == 0) return vector<int>();
        unordered_map<string, int> cs;
        for (string &wd : words) {
            if (!cs.count(wd)) cs[wd] = 1;
            else cs[wd] ++;
        }
        
        vector<int> res;
        int n = words[0].length();
        for (int i = 0; i < n; i ++) { // n sliding windows
            int lt = i, rt = i;
            
            while (lt < s.length()) {
                while (rt + n <= s.length()) {
                    string str = s.substr(rt, n);
                    if (cs.count(str) && cs[str] > 0) rt += n, cs[str] --;
                    else break;
                }
                if (rt - lt == words.size() * n) res.push_back(lt);
                if (lt == rt) lt += n, rt += n;
                else {
                    string str = s.substr(lt, n);
                    cs[str] ++;
                    lt += n;
                }
            }
        }
        
        return res;
    }
};