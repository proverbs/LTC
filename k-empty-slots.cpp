// tipical: reverse thinking

class Solution {
public:
    vector<int> lt;
    vector<int> rt;
    int kEmptySlots(vector<int>& flowers, int k) {
        int n = flowers.size();
        if (k >= n - 1) return -1;
        lt.push_back(0);
        rt.push_back(0);
        for (int i = 1; i <= n; i ++) {
            lt.push_back(i - 1);
            rt.push_back(i + 1);
        }
        lt[1] = -n;
        rt[n] = n + n;
        
        int res = -1;
        for (int i = n - 1; i >= 0; i --) {
            int x = flowers[i];
            int xlt = lt[x], xrt = rt[x];
            if (xrt - x - 1 == k || x - xlt - 1 == k) res = i + 1;
            if (xlt >= 1) rt[xlt] = xrt;
            if (xrt <= n) lt[xrt] = xlt;
        }
        return res;
    }
};