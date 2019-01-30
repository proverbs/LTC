class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int p = 0;
        while (p + 1 < bits.size()) {
            if (bits[p] == 1) p += 2;
            else p ++;
        }
        return p + 1 == bits.size();
    }
};