class Solution {
public:
    bool isPowerOfThree(int n) {
        long long mt = 1;
        while (mt * 3 <2147483647) mt *= 3;
        // cout << mt << endl;
        // hardcode this value of mt
        return n > 0 && mt % n == 0;
    }
};