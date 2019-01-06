class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        int cnt = 0;
        unordered_map<string, int> ct;
        for (pair<string, string>& pr : pairs) {
            if (!ct.count(pr.first)) ct[pr.first] = cnt ++;
            if (!ct.count(pr.second)) ct[pr.second] = cnt ++;
        }
        unordered_map<int, unordered_map<int, bool>> mp;
        for (pair<string, string>& pr : pairs) {
            int x = ct[pr.first], y = ct[pr.second];
            if (x > y) swap(x, y);
            if (mp.count(x)) {
                mp[x][y] = true;
            } else {
                mp[x] = unordered_map<int, bool>();
                mp[x][y] = true;
            }
        }
        if (words1.size() != words2.size()) return false;
        for (int i = 0; i < words1.size(); i ++) {
            if (words1[i] == words2[i]) continue;
            if (!ct.count(words1[i]) || !ct.count(words2[i])) return false;
            int x = ct[words1[i]], y = ct[words2[i]];
            if (x > y) swap(x, y);
            if (!mp.count(x) || !mp[x].count(y)) return false;
        }
        return true;
    }
};