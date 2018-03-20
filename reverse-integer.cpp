/**/

#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int fg = x < 0 ? -1 : 1;
        x = abs(x);
        long long res = 0;
        while (x) {
            res = res * 10 + x % 10;
            x /= 10;
        }
        res *= fg;
        return (res > 2147483647 || res < -2147483648) ? 0 : res;
    }
};

int main() {
    cout << Solution().reverse(1534236469) << endl;
    return 0;
}