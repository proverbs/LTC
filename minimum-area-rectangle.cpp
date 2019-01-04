class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, vector<int>> xs;
        for (int i = 0; i < points.size(); i ++) {
            int x = points[i][0], y = points[i][1];
            if (xs.count(x)) xs[x].push_back(y);
            else xs[x] = vector<int>({y});
        }
        for (auto& x : xs)
            sort(x.second.begin(), x.second.end());
        
        auto lt = xs.begin();
        int res = 1700000000;
        for (; lt != xs.end(); lt ++) {
            auto rt = lt;
            rt ++;
            for (; rt != xs.end(); rt ++) {
                vector<int>& a = lt->second;
                vector<int>& b = rt->second;
                unordered_map<int, bool> mp;
                for (int x : a) mp[x] = true;
                int last = -1;
                for (int i = 0; i < b.size(); i ++) {
                    if (mp.count(b[i])) {
                        if (last != -1) {
                            res = min(res, abs(rt->first - lt->first) * (b[i] - b[last]));
                        }
                        last = i;
                    }
                }
            }
        }
        
        return res == 1700000000 ? 0 : res;
    }
};