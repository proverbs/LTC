// rejection sampling: https://leetcode.com/problems/implement-rand10-using-rand7/solution/

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int x, y;
        while (true) {
            x = rand7();
            y = rand7();
            int z = 7 * (x - 1) + y;
            if (z <= 40) return (z - 1) % 10 + 1;
        }
    }
};