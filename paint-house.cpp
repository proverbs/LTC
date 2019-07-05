class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        if (!n) return 0;
        for (int i = 1; i < n; i ++) {
            for (int j = 0; j < 3; j ++) {
                int c = costs[i][j];
                costs[i][j] = 9999999;
                for (int k = 0; k < 3; k ++) {
                    if (k != j) costs[i][j] = min(costs[i][j], c + costs[i - 1][k]);
                }
            }
        }
        return min(costs[n - 1][0], min(costs[n - 1][1], costs[n - 1][2]));
    }
};