// the way to construct gray code

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res(1 << n, 0);
        if (!n) return res;

        res[0] = 0;
        res[1] = 1;

        for (int i = 1; i < n; i ++) {
            int tn = 1 << i;
            for (int j = tn; j < 2 * tn; j ++)
                res[j] = res[2 * tn - j - 1] | (1 << i);
        }

        return res;
    }
};