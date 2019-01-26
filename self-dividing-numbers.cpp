// brute force

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for (int i = left; i <= right; i ++)
            if (check(i)) res.push_back(i);
        return res;
    }
    
    bool check(int x) {
        int z = x;
        while (x) {
            int y = x % 10;
            if (!y || z % y) return false;
            x /= 10;
        }
        return true;
    }
};