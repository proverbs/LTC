/*用一行记录哪些列需要编程0*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> >& matrix) {
        int n = matrix.size();
        if (n == 0) return;
        int m = matrix[0].size();
        int mxrow = -1;
        for (int i = 0; i < n; i ++) {
            int j = 0;
            for (; j < m; j ++) {
                if (matrix[i][j] == 0) break;
            }
            if (j != m) {
                mxrow = i;
                break;
            }
        }
        if (mxrow == -1) return;
        for (int i = 0; i < n; i ++) {
            if (i == mxrow) continue;
            for (int j = 0; j < m; j ++) {
                if (matrix[i][j] == 0) matrix[mxrow][j] = 0;
            }
        }
        for (int i = 0; i < n; i ++) {
            if (i == mxrow) continue;
            int j = 0;
            for (; j < m; j ++) {
                if (matrix[i][j] == 0) break;
            }
            if (j != m) {
                for (j = 0; j < m; j++) matrix[i][j] = 0;
            }
        }
        for (int j = 0; j < m; j ++) {
            if (matrix[mxrow][j] == 0) {
                for (int i = 0; i < n; i ++) matrix[i][j] = 0;
            }
            matrix[mxrow][j] = 0;
        }
    }
};

int main() {
    vector<int> z;
    z.push_back(1);
    vector<vector<int> > v;
    v.push_back(z);
    Solution().setZeroes(v);
    return 0;
}