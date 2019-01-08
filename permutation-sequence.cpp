class Solution {
public:
    vector<int> factorial;
    string getPermutation(int n, int k) {
        vector<int> cand;
        for (int i = 1; i <= n; i ++) cand.push_back(i);
        int f = 1;
        factorial.push_back(1);
        for (int i = 1; i < n; i ++) factorial.push_back(factorial[i - 1] * i);
        return dfs(cand, k);
    }
    
    string dfs(vector<int>& cand, int k) {
        int n = cand.size();
        if (!n) return "";
        for (int i = 0; i < n; i ++) {
            if (k > factorial[n - 1]) k -= factorial[n - 1];
            else {
                string res;
                res.push_back('0' + cand[i]);
                cand.erase(cand.begin() + i);
                return res += dfs(cand, k);
            }
        }
    }
};