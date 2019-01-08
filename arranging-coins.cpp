class Solution {
public:
    int arrangeCoins(int n) {
        long long res = floor(sqrt(2.0 * n)) - 1;
        while ((res + 1) * (2 + res) / 2 <= n) res ++;
        return res;
    }
};