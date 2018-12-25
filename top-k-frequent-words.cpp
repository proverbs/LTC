// O(n + klogk)

typedef pair<int, string> pis;
class Solution {
public:
    class Compare {
    public:
        bool operator() (const pis &a, const pis &b) {
            if (a.first == b.first) return a.second < b.second;
            return a.first > b.first;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> cs;
        for (int i = 0; i < words.size(); i ++) {
            if (!cs.count(words[i])) cs[words[i]] = 0;
            cs[words[i]] ++;
        }
        
        priority_queue<pis, vector<pis>, Compare> pq;
        unordered_map<string, int>::iterator it;
        for (it = cs.begin(); it != cs.end(); it ++) {
            pq.push(make_pair(it->second, it->first));
            if (pq.size() == k + 1) pq.pop();
        }
        
        vector<string> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};