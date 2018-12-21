// formula for sum of arithmetic progression
class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int n = sqrt(2.0 * N);
        int res = 1;
        for (int i = 2; i <= n; i ++) {
            if (2 * N % i == 0) {
                int z = 2 * N / i + 1 - i;
                if (z > 0 && z % 2 == 0) res ++;
            }
        }
        return res;
    }
};