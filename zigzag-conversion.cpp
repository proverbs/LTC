// another way is to calculate the index of each element

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<vector<char>> z(numRows, vector<char>(s.length(), '#'));
        int x = 0, y = 0;
        for (int i = 0; i < s.length(); i ++) {
            z[x][y] = s[i];
            if (x == numRows - 1) y ++, x --;
            else if (y % (numRows - 1) == 0) x ++;
            else y ++, x --;
        }
        string res;
        for (int i = 0; i < numRows; i ++) {
            for (int j = 0; j < s.length(); j ++) {
                if (z[i][j] != '#') res.push_back(z[i][j]);
            }
        }
        return res;
    }
};