/*sort, 贪心*/

class Solution {
public:
    vector<pair<int, int> > reconstructQueue(vector<pair<int, int> >& people) {
        sort(people.begin(), people.end(), cmp);
        vector<pair<int, int> > res;
        for (int i = 0; i < people.size(); i ++) {
            res.insert(res.begin() + people[i].second, people[i]);
        }
        return res;
    }

    static bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    }
};