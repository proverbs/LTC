/*brute force, recursion*/

#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.length() == 0) return res;
        string s[] = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> mp(s, s + 9);
        dfs(digits, 0, "", res, mp);
        return res;
    }
    
    void dfs(string d, int x, string s, vector<string>& res, vector<string>& mp) {
        if (x == d.length()) res.push_back(s);
        for (int i = 0; i < mp[d[x] - '1'].size(); i++) {
            string tmp = s;
            tmp.push_back(mp[d[x] - '1'][i]);
            dfs(d, x + 1, tmp, res, mp);
        }
    }
};

int main() {
    cout << Solution().letterCombinations("23").size() << endl;
    return 0;
}