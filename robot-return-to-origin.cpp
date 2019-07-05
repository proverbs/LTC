class Solution {
public:
    bool judgeCircle(string moves) {
        int dx = 0, dy = 0;
        for (char c: moves) {
            if (c == 'U') dy ++;
            else if (c == 'D') dy --;
            else if (c == 'L') dx --;
            else dx ++;
        }
        return dx == 0 && dy == 0;
    }
};