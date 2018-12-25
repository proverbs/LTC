// The definition of a celebrity is that all the other n - 1 people know him/her but he/she does not know any of them.
// O(n)

// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        int res = 0;
        for (int i = 0; i < n; i ++) {
            if (knows(res, i)) res = i;
        }
        
        for (int i = 0; i < n; i ++) {
            if (i == res) continue;
            if (!knows(i, res)) return -1;
            if (knows(res, i)) return -1;
        }
        return res;
    }
};