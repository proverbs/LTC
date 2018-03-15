/*lowbit, dp*/

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res;
        res.push_back(0);
        for (int i = 1; i <= num; i ++) {
            res.push_back(res[i - lowbit(i)] + 1);
        } 
        return res;
    }

    int lowbit(int x) {
        return x & -x;
    }
};