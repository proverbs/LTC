// math: congruence group

class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int res = 0;
        vector<int> bucket(K, 0);
        vector<int> sums(A.size(), 0);
        sums[0] = (A[0] % K + K) % K;
        for (int i = 1; i < A.size(); i ++)
            sums[i] = ((sums[i - 1] + A[i]) % K + K) % K;
        bucket[0] = 1;
        for (int i = 0; i < sums.size(); i ++) {
            res += bucket[sums[i]];
            bucket[sums[i]] ++;
            
        }
        return res;
    }
};