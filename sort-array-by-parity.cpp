class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int j = 0;
        for (int i = 0; i < A.size(); i ++)
            if (!(A[i] & 1)) swap(A[i], A[j ++]);
        return A;
    }
};