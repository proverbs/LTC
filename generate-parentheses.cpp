/*dfs*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s = "";
        dfs(s, n, n, res, 2 * n);
        return res;
    }

    void dfs(string s, int nl, int nr, vector<string>& res, int len) {
        //cout << s << endl;
        if (s.length() == len) {
            res.push_back(s);
            return;
        }
        if (s.length() == 0) {
            if (nl) {
                dfs(s + "(", nl - 1, nr, res, len);
            }
        }
        else {
            if (nl == nr) {
                dfs(s + "(", nl - 1, nr, res, len);
            }
            else {
                if (nl) dfs(s + "(", nl - 1, nr, res, len);
                dfs(s + ")", nl, nr - 1, res, len);
            }
        } 
    }
};

int main() {
    cout << Solution().generateParenthesis(3).size() << endl;
    return 0;
}