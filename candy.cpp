// longest consecutive ascending subarray

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> xlen(ratings.size(), 1);
        int x = 1;
        for (int i = 1; i < ratings.size(); i ++) {
            if (ratings[i] > ratings[i - 1]) x ++, xlen[i] = max(xlen[i], x);
            else x = 1;
        }
        for (int i = ratings.size() -2; i >= 0; i --) {
            if (ratings[i] > ratings[i + 1]) x ++, xlen[i] = max(xlen[i], x);
            else x = 1;
        }
        int res = 0;
        for (int i = 0; i < ratings.size(); i ++) res += xlen[i];
        return res;
    }
};