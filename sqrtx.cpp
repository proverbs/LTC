/*二分*/

class Solution {
public:
    int mySqrt(int x) {
        int lt = 0, rt = min(x, 46340);// sqrt(2147483647)
        int res;
        while (lt <= rt) {
            int mid = lt + rt >> 1;
            if (mid * mid <= x) res = mid, lt = mid + 1;
            else rt = mid - 1;
        }
        return res;
    }
};