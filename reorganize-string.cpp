// interleaving according to count. It is less strict than wiggle sort.

class Solution {
public:
    typedef pair<char, int> pr; // <char, count>
    static bool cmp(const pr& a, const pr& b) {
        if (a.second == b.second) return a.first < b.first;
        return a.second > b.second;
    }
    string reorganizeString(string S) {
        vector<int> ct(26, 0);
        for (char a : S) ct[a - 'a'] ++;
        vector<pr> v;
        for (char a : S) v.push_back({a, ct[a - 'a']});
        sort(v.begin(), v.end(), cmp);
        
        int n = S.length();
        string res(n, '0');
        for (int i = 0; i < n; i ++) {
            if (n & 1) res[(i << 1) % n] = v[i].first;
            else {
                if ((i << 1) < n) res[i << 1] = v[i].first;
                else res[(i << 1) % n + 1] = v[i].first;
            }
        }
        for (int i = 1; i < n; i ++)
            if (res[i] == res[i - 1]) return "";
        return res;
    }
};