class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1 = tovector(version1);
        vector<int> v2 = tovector(version2);
        int idx = 0;
        while (idx < v1.size() || idx < v2.size()) {
            int v1n = 0, v2n = 0;
            if (idx < v1.size()) v1n = v1[idx];
            if (idx < v2.size()) v2n = v2[idx];
            
            if (v1n == v2n) idx ++;
            else if (v1n < v2n) return -1;
            else return 1;
        }
        return 0;
    }
    
    vector<int> tovector(string s) {
        vector<int> res;
        int x = 0;
        for (int i = 0; i < s.length(); i ++) {
            if (s[i] == '.') {
                res.push_back(x);
                x = 0;
            } else {
                x = x * 10 + s[i] - '0';
            }
        }
        res.push_back(x);
        return res;
    }
};