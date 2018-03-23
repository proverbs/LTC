/*递推*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> p;
        for (int i = 0; i < numRows; i ++) {
            vector<int> v;
            v.push_back(1);
            if (i > 0) {
                for (int j = 1; j < i; j ++)
                    v.push_back(p[i - 1][j - 1] + p[i - 1][j]);
                v.push_back(1);
            }
            p.push_back(v);
        }
        return p;
    }
};