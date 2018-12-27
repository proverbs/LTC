// sieve method
// O(n)

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> vis(n, false);
        int res = 0;
        for (int i = 2; i < n; i ++) {
            if (vis[i]) continue;
            int x = i;
            while (x + i < n) vis[x + i] = true, x += i;
        }
        for (int i = 2; i < n; i ++) 
            res += !vis[i];
        return res;
    }
};