// classic
// matrix fast power

class Solution {
public:
    int fib(int N) {
        if (N == 0) return 0;
        if (N == 1) return 1;
        N -= 2;
        
        vector<vector<int>> v(3, vector<int>(1, 0));
        v[1][0] = v[2][0] = 1;
        // {{0}, 
        // {1},
        // {1}}
        
        vector<vector<int>> m(3, vector<int>(3, 0));
        m[0][1] = m[1][2] = m[2][1] = m[2][2] = 1;
        // {{0, 1, 0}, 
        // {0, 0, 1},
        // {0, 1, 1}}
        
        vector<vector<int>> a(3, vector<int>(3, 0));
        a[0][0] = a[1][1] = a[2][2] = 1;
        // {{1, 0, 0}, 
        // {0, 1, 0},
        // {0, 0, 1}};
        
        
        while (N) {
            if (N & 1) a = calc(a, m);
            m = calc(m, m);
            N >>= 1;
        }
        
        v = calc(a, v);
        
        return v[2][0];
    }
    
    vector<vector<int>> calc(const vector<vector<int>>& x, const vector<vector<int>>& y) {
        vector<vector<int>> z(3, vector<int>(3, 0));
        for (int i = 0; i < x.size(); i ++) {
            for (int j = 0; j < y[0].size(); j ++) {
                for (int k = 0; k < x[0].size(); k ++) {
                    z[i][j] += x[i][k] * y[k][j];
                }
            }
        }
        return z;
    }
};