// binary search the result: O(log(MAX_INT) * row * log(col))

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), m = matrix[0].size();
        int lt = matrix[0][0], rt = matrix[n - 1][m - 1];
        int res;
        while (lt <= rt) {
            int mid = (long long)lt + rt >> 1;
            int z = num_less(matrix, mid);
            if (z >= k) res = mid, rt = mid -1;
            else lt = mid + 1;
        }
        return res;
    }
    
    int num_less(vector<vector<int>>& mx, int val) {
        int res = 0;
        for (int i = 0; i < mx.size(); i ++) {
            int z = upper_bound(mx[i].begin(), mx[i].end(), val) - mx[i].begin();
            res += z;
        }
        return res;
    }
};