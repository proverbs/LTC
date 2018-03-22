/*dfs*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static const int dx[4];
    static const int dy[4];
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> res;
        int n = matrix.size();
        if (!n) return res;
        int m = matrix[0].size();
        dfs(0, 0, 0, res, matrix, n, m, 0);
        return res;
    }

    void dfs(int x, int y, int d, vector<int>& res, vector<vector<int> >& matrix, int n, int m, int c) {
        // cout << x << " " << y << endl;
        res.push_back(matrix[x][y]);
        if (res.size() == n * m) return;
        int ax = x + dx[d];
        int ay = y + dy[d];
        if (ax < c || ax >= n - c || ay < c || ay >= m - c) {
            d = (d + 1) % 4;
            ax = x + dx[d];
            ay = y + dy[d];
        }
        if (ax == c && ay == c) {
            c ++;
            d = (d + 1) % 4;
            ax = x + dx[d];
            ay = y + dy[d];
        }
        dfs(ax, ay, d, res, matrix, n, m, c);
    }
};

const int Solution::dx[4] = {0, 1, 0, -1};
const int Solution::dy[4] = {1, 0, -1, 0};


int main() {
    int a[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> v0(a[0], a[0] + 3);
    vector<int> v1(a[1], a[1] + 3);
    vector<int> v2(a[2], a[2] + 3);
    vector<vector<int> > matrix;
    matrix.push_back(v0);
    matrix.push_back(v1);
    matrix.push_back(v2);
    cout << Solution().spiralOrder(matrix).size() << endl;
    return 0;
}