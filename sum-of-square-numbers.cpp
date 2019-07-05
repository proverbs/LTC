// same as 2sum

class Solution {
public:
    bool judgeSquareSum(int c) {
        unordered_map<int, bool> st;
        long long lc = c;
        for (long long i = 0; i * i <= lc; i ++) {
            st[i * i] = true;
            if (st.count(lc - i * i)) return true;
        }
        return false;
    }
};