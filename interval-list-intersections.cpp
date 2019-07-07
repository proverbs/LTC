// merge ordered intervals

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res;
        int lt, rt;
        
        int pa = 0, pb = 0;
        int idx = 0;
        while (pa < A.size() && pb < B.size()) {
            if (A[pa][1] < B[pb][0]) pa ++;
            else if (B[pb][1] < A[pa][0]) pb ++;
            else if (A[pa][1] >= B[pb][0]) {
                int lt = max(A[pa][0], B[pb][0]);
                int rt = min(A[pa][1], B[pb][1]);
                res.push_back(vector<int>({lt, rt}));
                if (A[pa][1] < B[pb][1]) B[pb][0] = A[pa ++][1];
                else if (A[pa][1] > B[pb][1]) A[pa][0] = B[pb ++][1];
                else pa ++, pb ++;
            }
        }
        
        return res;
    }
};