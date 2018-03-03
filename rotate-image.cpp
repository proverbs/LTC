/*simulation*/
/*将沿副对角线翻折转化为沿主对角线翻折（每行先rotate+翻折+行rotate）*/
/*本方法是获取交换链*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {
        int n = matrix.size();
        int sx = 0;
        for (int sx = 0; sx <= n / 2; sx ++)
            for (int sy = sx; sy < n - 1 - sx; sy ++) {
                dswap(sx, sy, sy, n - sx - 1, n, matrix);
            }
    }

    void dswap(int x, int y, int sx, int sy, int n, vector<vector<int> >& matrix) {
        //cout << sx << " " << sy << endl;
        if (sx == x && sy == y) return;
        swap(matrix[x][y], matrix[sx][sy]);
        dswap(x, y, sy, n - sx - 1, n, matrix);
    }
};

int main() {
    int a[] = {7, 4, 1};
    int b[] = {8, 5, 2};
    int c[] = {9, 6, 3};
    vector<int> va(a, a + 3);
    vector<int> vb(b, b + 3);
    vector<int> vc(c, c + 3);
    vector<vector<int> > s;
    s.push_back(va);
    s.push_back(vb);
    s.push_back(vc);
    Solution().rotate(s);
    return 0;
}