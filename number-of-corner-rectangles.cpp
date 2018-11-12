// general solution not only for 0/1 matrix
// Time complexity: O(n^3)
// Space complexity: O(n)

#include <map>

class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int res = 0;
        if (grid.size() == 0) return res;
        
        for (int i = 0; i < grid.size(); i ++) {
            for (int j = i + 1; j < grid.size(); j ++) {
                unordered_map<int, int> ump;
                for (int k = 0; k < grid[0].size(); k ++) {
                    if (grid[i][k] != 0 && grid[i][k] == grid[j][k]) {
                        int &z = grid[i][k];
                        if (ump.count(z)) {
                            res += ump[z];
                            ump[z] ++;
                        } else {
                            ump[z] = 1;
                        }
                    }
                }
            }
        }
        return res;
    }
};