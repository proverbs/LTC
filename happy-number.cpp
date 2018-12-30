class Solution {
public:
    unordered_map<int, bool> vis;
    bool isHappy(int n) {
        if (vis.count(n)) return false;
        if (n == 1) return true;
        vis[n] = true;
        int res = 0;
        while (n) res += (n % 10) * (n % 10), n /= 10;
        return isHappy(res);
    }
};