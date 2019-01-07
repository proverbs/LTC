// matrix fast power

class Solution {
public:
    int knightDialer(int N) {
        vector<vector<long long>> tm(10, vector<long long>(10, 0));
        tm[0][4] = tm[0][6] = 1;
        tm[1][6] = tm[1][8] = 1;
        tm[2][7] = tm[2][9] = 1;
        tm[3][4] = tm[3][8] = 1;
        tm[4][3] = tm[4][9] = tm[4][0] = 1;
        tm[6][1] = tm[6][7] = tm[6][0]  = 1;
        tm[7][2] = tm[7][6] = 1;
        tm[8][1] = tm[8][3] = 1;
        tm[9][2] = tm[9][4] = 1;
        vector<long long> dp(10, 1);
        
        int k = N - 1;
        while (k) {
            if (k & 1) dp = mul1(tm, dp);
            tm = mul2(tm, tm);
            k >>= 1;
        }
        
        long long res = 0;
        long long mod = 1e9 + 7;
        for (long long a : dp) res = (res + a) % mod;
        return res;
    }
    
    vector<long long> mul1(const vector<vector<long long>>& tm, const vector<long long>& dp) {
        static long long mod = 1e9 + 7;
        vector<long long> res(10, 0);
        for (int i = 0; i < 10; i ++)
            for (int j = 0; j < 10; j ++) {
                res[i] += tm[i][j] * dp[j];
                res[i] %= mod;
            }
        return res;
    }
    
    vector<vector<long long>> mul2(const vector<vector<long long>>& a, const vector<vector<long long>>& b) {
        static long long mod = 1e9 + 7;
        vector<vector<long long>> res(10, vector<long long>(10, 0));
        for (int i = 0; i < 10; i ++)
            for (int j = 0; j < 10; j ++)
                for (int k = 0; k < 10; k ++) {
                    res[i][j] += a[i][k] * b[k][j];
                    res[i][j] %= mod;
                }
        return res;
    }
};