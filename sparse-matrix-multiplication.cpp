class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> arow(A.size(), vector<int>());
        for (int i = 0; i < A.size(); i ++)
            for (int j = 0; j < A[i].size(); j ++)
                if (A[i][j]) arow[i].push_back(j);
        vector<vector<int>> bcol(B[0].size(), vector<int>());
        for (int j = 0; j < B[0].size(); j ++)
            for (int i = 0; i < B.size(); i ++)
                if (B[i][j]) bcol[j].push_back(i);
        
        vector<vector<int>> res(A.size(), vector<int>(B[0].size(), 0));
        for (int i = 0; i < res.size(); i ++)
            for (int j = 0; j < res[0].size(); j ++) {
                int la = 0, lb = 0;
                while (la < arow[i].size() && lb < bcol[j].size()) {
                    if (arow[i][la] == bcol[j][lb]) res[i][j] += A[i][arow[i][la ++]] * B[bcol[j][lb ++]][j];
                    else if (arow[i][la] < bcol[j][lb]) la ++;
                    else lb ++;
                }
            }
        return res;
    }
};