// map + two pointers merge

class WordDistance {
public:
    vector<string> wds;
    unordered_map<string, vector<int>> idx;
    WordDistance(vector<string> words) : wds(words) {
        for (int i = 0; i < wds.size(); i ++) {
            if (!idx.count(wds[i])) idx[wds[i]] = vector<int>();
            idx[wds[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        vector<int> &a = idx[word1];
        vector<int> &b = idx[word2];
        int last = -1;
        int pa = 0, pb = 0, res = wds.size();
        while (pa < a.size() || pb < b.size()) {
            if (pa >= a.size()) {
                if (last != -1 && wds[last] != wds[b[pb]]) res = min(res, abs(last - b[pb]));
                last = b[pb];
                pb ++;
            } else if (pb >= b.size()) {
                if (last != -1 && wds[last] != wds[a[pa]]) res = min(res, abs(last - a[pa]));
                last = a[pa];
                pa ++;
            } else {
                if (b[pb] < a[pa]) {
                    if (last != -1 && wds[last] != wds[b[pb]]) res = min(res, abs(last - b[pb]));
                    last = b[pb];
                    pb ++;
                } else {
                    if (last != -1 && wds[last] != wds[a[pa]]) res = min(res, abs(last - a[pa]));
                    last = a[pa];
                    pa ++;
                }
            }
        }
        return res;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */