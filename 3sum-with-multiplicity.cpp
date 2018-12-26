// O(n^2)

class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        int res = 0;
        int mod = 1e9 + 7;
        for (int i = 0; i < A.size(); i ++) {
            vector<int> cs(101, 0);
            for (int k = i + 1; k < A.size(); k ++) {
                int z = target - A[i] - A[k];
                if (z >= 0 && z <= 100) res = (res + cs[z]) % mod;
                cs[A[k]] ++;
            }
        }
        return res;
    }
};