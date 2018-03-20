/*二分+快速乘*/

#include <iostream>

using namespace std;

const int INT_MAX = 999, INT_MIN = -999;

class Solution {
public:
    int divide(int dividend, int divisor) {
        long long x = dividend, y = divisor;
        long long ans;
        int fg = 1;
        if (x < 0) fg *= -1, x = -x;
        if (y < 0) fg *= -1, y = -y;
        long long lt = 0, rt = -(long long)INT_MIN;
        while (lt <= rt) {
            long long mid = lt + rt >> 1LL;
            long long res = 0;
            long long z = y;
            while (mid) {
                if (mid & 1LL) res += z;
                z += z;
                mid >>= 1;
            }
            mid = lt + rt >> 1LL;
            if (res <= x) {
                ans = mid;
                lt = mid + 1LL;
            } else {
                rt = mid - 1LL;
            }
        }
        ans *= fg;
        if (ans > (long long)INT_MAX || ans < (long long)INT_MIN) return INT_MAX;
        return ans;
    }
};

int main() {
    cout << Solution().divide(1, 1) << endl;
    return 0;
}