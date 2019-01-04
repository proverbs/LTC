// manhattan distance: x and y are independent

class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<int> xs, ys;
        vector<pair<int, int>> pr;
        for (int i = 0; i < grid.size(); i ++) 
            for (int j = 0; j < grid[0].size(); j ++) 
                if (grid[i][j]) {
                    xs.push_back(i);
                    ys.push_back(j);
                    pr.push_back({i, j });
                }
        sort(xs.begin(), xs.end());
        sort(ys.begin(), ys.end());
        int resx = xs[pr.size() >> 1];
        int resy = ys[pr.size() >> 1];
        int res = 0;
        for (pair<int, int>& a : pr) res += abs(a.first - resx) + abs(a.second - resy);
        return res;
    }
};