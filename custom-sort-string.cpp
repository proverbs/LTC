// quick sort

class Solution {
public:
    static vector<int> idx;
    string customSortString(string S, string T) {
        for (int i = 0; i < S.length(); i ++) idx[S[i] - 'a'] = i;
        sort(T.begin(), T.end(), cmp);
        return T;
    }
    
    static bool cmp(const char& a, const char& b) {
        return idx[a - 'a'] < idx[b - 'a'];
    }
};

vector<int> Solution::idx(26, 0);



// counting sort
class Solution {
public:
    string customSortString(string S, string T) {
        vector<int> idx(26, -1), ct(26, 0);
        for (int i = 0; i < S.length(); i ++) idx[S[i] - 'a'] = i;
        string bk;
        for (char c : T) {
            if (idx[c - 'a'] != -1) ct[idx[c - 'a']] ++;
            else bk.push_back(c);
        }
        
        string res;
        for (int i = 0; i < 26; i ++)
            while (ct[i] -- ) res.push_back(S[i]);
        return res + bk;
    }
};