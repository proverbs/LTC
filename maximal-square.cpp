/*dp*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char> >& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        vector<int> v(matrix[0].size(), 0);
        vector<vector<int> > dp;
        for (int i = 0; i < matrix.size(); i ++) dp.push_back(v);
        int res = 0;
        for (int i = 0; i < matrix.size(); i ++) {
            for (int j = 0; j < matrix[0].size(); j ++) {
                if (matrix[i][j] == '1') {
                    int z;
                    dp[i][j] = 1;
                    z = i - 1 >= 0 ? dp[i - 1][j] : 0;
                    z = j - 1 >= 0 ? min(z, dp[i][j - 1]) : 0;
                    if (matrix[i - z][j - z] != '1') z --; // 细节
                    dp[i][j] = max(dp[i][j], z + 1);
                    res = max(res, dp[i][j]);
                }
            }
        }
        return res * res;
    }
};

int main() {
    vector<vector<char> > s;
    vector<char> v;
    v.push_back('0');v.push_back('1');v.push_back('1');v.push_back('0');v.push_back('1');
    s.push_back(v);
    v[0]  = '1';v[1] = '1';v[2] = '0';v[3] = '1';v[4] = '0';
    s.push_back(v);
    v[0]  = '0';v[1] = '1';v[2] = '1';v[3] = '1';v[4] = '0';
    s.push_back(v);
    v[0]  = '1';v[1] = '1';v[2] = '1';v[3] = '1';v[4] = '0';
    s.push_back(v);
    v[0]  = '1';v[1] = '1';v[2] = '1';v[3] = '1';v[4] = '1';
    s.push_back(v);
    v[0]  = '0';v[1] = '0';v[2] = '0';v[3] = '0';v[4] = '0';
    s.push_back(v);
    cout << Solution().maximalSquare(s) << endl;
    return 0;
}