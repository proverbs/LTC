// typical: next permutation

class Solution {
public:
    int nextGreaterElement(int n) {
        string sn = to_string(n), tn = sn;
        for (int i = sn.length() - 2; i >= 0; i --) 
            if (sn[i] < sn[i + 1]) {
                int idx = i + 1;
                for (int j = i + 1; j < sn.length(); j ++)
                    if (sn[j] > sn[i] && sn[j] <= sn[idx]) idx = j; // e.g. 12222333
                swap(sn[i], sn[idx]);
                reverse(sn.begin() + i + 1, sn.end());
                break;
            }
        if (sn == tn) return -1;
        long long z;
        sscanf(sn.c_str(), "%lld", &z);
        if (z > 2147483647LL) return -1;
        return z;
    }
};