class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> res;
        if (A.empty()) return res;
        
        int lt = 0, rt = A.size() - 1;
        int sa, sb;
        while (lt <= rt) {
            sa = A[lt] * A[lt];
            sb = A[rt] * A[rt];
            if (sa > sb) res.push_back(sa), lt ++;
            else res.push_back(sb), rt --;
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};