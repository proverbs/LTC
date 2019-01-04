// Math: https://leetcode.com/problems/poor-pigs/discuss/94266/Another-explanation-and-solution
// it is quite a typical method.

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        long long mtd = minutesToDie;
        long long mtt = minutesToTest;
        long long b = buckets;
        long long pig = 0;
        while (pow(mtt / mtd + 1, pig) < b) pig ++;
        return pig;
    }
};