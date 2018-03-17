/*dfs, 比较难*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        set<string> st;
        dfs(s, st, '(', ')');
        for (set<string>::iterator it = st.begin(); it != st.end(); it ++) {
            res.push_back(*it);
        }
        return res;
    }

    void dfs(string s, set<string>& st, char pos, char neg) {
        //cout << pre << "==" << s << "==" << suf << endl;
        int cnt = 0;
        string ts;
        for (int i = 0; i < s.length(); i ++) {
            if (s[i] == pos) cnt ++;
            else if (s[i] == neg) cnt --;
            if (cnt >= 0) continue;
            // 此时可以删除i之前的所有neg
            char lst = '@';
            for (int j = 0; j <= i; j ++) {
                if (s[j] == neg && s[j] != lst) {
                    ts = s.substr(0, j) + s.substr(j + 1, i - j);
                    if (pos == '(') {
                        //dfs(s.substr(i + 1), st, pos, neg, pre + ts, suf);
                        dfs(ts + s.substr(i + 1), st, pos, neg); // 可能出现重复
                    }
                    else {
                        string ss = s.substr(i + 1);
                        reverse(ss.begin(), ss.end());
                        reverse(ts.begin(), ts.end());
                        //cout << ss << "      " << sk << endl;
                        //dfs(ss, st, neg, pos, pre, ts + suf);
                        dfs(ss + ts, st, neg, pos);
                    }
                }
                lst = s[j];
            }
            return;
        }
        if (cnt == 0) {
            st.insert(s);
            // cout << "res: " << pre + s + suf << endl;
        } else {
            // 翻转检测
            //cout << "dfs" << endl;
            reverse(s.begin(), s.end());
            dfs(s, st, neg, pos);
        }
    }
};

int main() {
    string s = "(((k()((";
    cout << Solution().removeInvalidParentheses(s).size() << endl;
    return 0;
}