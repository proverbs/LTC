/*math , dp*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        m --;
        n --;
        if (m == 0 || n == 0) return 1;
        int s = m + n;
        int x = min(m, n);
        long long ans = 1;
        for (int i = s; i >= s - x + 1; i --) ans *= (long long)i;
        for (int i = x; i > 0; i --) ans /= (long long)i;
        return ans;
    }
};