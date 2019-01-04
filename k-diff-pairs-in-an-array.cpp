class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) return 0;
        unordered_map<int, bool> vis;
        int res = 0;
        unordered_map<int, unordered_map<int, bool>> qc;
        for (int x : nums) {
            if (vis.count(x - k)) {
                if (qc.count(x - k)) {
                    if (!qc[x - k].count(x)) qc[x - k][x] = true, res ++;
                } else {
                    res ++;
                    qc[x - k] = unordered_map<int, bool>();
                    qc[x - k][x] = true;
                }
            }
            if (vis.count(x + k)) {
                if (qc.count(x)) {
                    if (!qc[x].count(x + k)) qc[x][x + k] = true, res ++;
                } else {
                    res ++;
                    qc[x] = unordered_map<int, bool>();
                    qc[x][x + k] = true;
                }
            }
            vis[x] = true;
        }
        return res;
    }
};