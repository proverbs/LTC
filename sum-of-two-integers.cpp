// add using 1's complement

class Solution {
public:
    int getSum(int a, int b) {
        bool jin = false;
        int res = 0;
        for (int i = 0; i < 32; i ++) {
            bool ax = (a >> i) & 1, bx = (b >> i) & 1;
            bool z = ax ^ bx ^ jin;
            if (z) res |= 1 << i;
            if ((ax && bx) || (ax && jin) || (bx && jin)) jin = 1;
            else jin = 0;
        }
        return res;
    }
};