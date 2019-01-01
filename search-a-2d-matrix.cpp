// lower_bound: first x >= val
// upper_bound: first x > val

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        vector<int> a;
        for (int i = 0; i < matrix.size(); i ++)
            a.push_back(matrix[i][0]);
        int k = upper_bound(a.begin(), a.end(), target) - a.begin();
        k --;
        if (k == -1) return false;
        
        int z = lower_bound(matrix[k].begin(), matrix[k].end(), target) - matrix[k].begin();
        if (z == matrix[0].size()) return false;
        
        return matrix[k][z]  == target;
    }
};