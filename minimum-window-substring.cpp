/*two pointers, slide window*/
/*typical*/

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (t.length() == 0) return "";
        map<char, int> ct;
        map<char, int> org;
        set<char> st;
        for (int i = 0; i < t.length(); i ++) {
            st.insert(t[i]);
            org[t[i]] ++; // 默认为0
        }
        int lt = 0, rt = 0;
        string res;
        int res_lt = 0, res_rt = 9999999;
        while (rt <= s.length()) {
            // 右侧右移
            while (rt < s.length() && !check(ct, org, st)) {
                ct[s[rt ++]] ++;
            }
            if (rt >= s.length() && !check(ct, org, st)) break;
            // 左侧右移
            while (check(ct, org, st)) {
                ct[s[lt ++]] --;
            }
            // 更新最优值
            if (res_rt - res_lt > rt - lt + 1) {
                res_rt = rt;
                res_lt = lt - 1;
            }
        }
        if (res_rt == 9999999) return "";
        return s.substr(res_lt, res_rt - res_lt);
    }

    bool check(map<char, int>& ct, map<char, int>& org, set<char>& st) {
        set<char>::iterator it;
        for (it = st.begin(); it != st.end(); it ++) {
            if (ct[*it] < org[*it]) return false;
        }
        return true;
    }
};

int main() {
    cout << Solution().minWindow("a", "aa") << endl;
    return 0;
}