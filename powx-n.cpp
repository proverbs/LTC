/*快速幂*/

class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        bool fg = false;
        long long nn = n;
        if (nn < 0) fg = 1, nn = -nn;
        while (nn) {
            if (nn & 1LL) res *= x;
            x *= x;
            nn >>= 1LL;
        }
        return fg ? 1.0 / res : res;
    }
};