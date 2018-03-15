/*dfs, 括号匹配*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        return dec(s, 0, s.length() - 1);
    }

    string dec(string& s, int lt, int rt) {
        string res = "";
        if (lt > rt) return res;
        if (isNumber(s[lt])) {
            int cnt;
            pair<int, int> p = getNumber(s, lt, cnt);
            string t = dec(s, p.first + 1, p.second - 1);
            for (int i = 0; i < cnt; i ++) res += t;
            res += dec(s, p.second + 1, rt);
        } else {
            while (lt <= rt && !isNumber(s[lt])) {
                res.push_back(s[lt ++]);
            }
            if (lt <= rt) res += dec(s, lt, rt);
        }
        return res;
    }

    bool isNumber(char a) {
        return a >= '0' && a <='9';
    }

    pair<int, int> getNumber(string& s, int x, int& cnt) {
        cnt = 0;
        while (isNumber(s[x])) {
            cnt = cnt * 10 + s[x] - '0';
            x ++;
        }
        int z = 1;
        int y = x + 1;
        while (z != 0) {
            if (s[y] == '[') z ++;
            else if (s[y] == ']') z --;
            y ++;
        }
        return make_pair(x, y - 1);
    }
};

int main() {
    string s = "3[a]2[bc]";
    cout << Solution().decodeString(s) << endl;
    return 0;
}