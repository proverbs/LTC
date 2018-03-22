/*递推, re????*/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        vector<int> s;
        s.push_back(1);
        for (int i = 1; i <= n; i ++) {
            vector<int> ts;
            int lt = 0, rt = 1;
            while (lt != s.size()) {
                while (lt != s.size() && s[rt] == s[lt]) rt ++;
                ts.push_back(rt - lt);
                ts.push_back(s[lt]);
                lt = rt;
                rt ++;
            }
            //s = ts;
            s.assign(ts.begin(), ts.end());
        }
        return toString(s);
    }

    string toString(vector<int>& v) {
        string res;
        stringstream st;
        for (int i = 0; i < v.size(); i += 2) {
            st.clear();
            st << v[i + 1];
            string ts;
            st >> ts;
            for (int j = 0; j < v[i]; j ++) {
                res = res + ts;
            }
        }
        return res;
    }
};

int main() {
    cout << Solution().countAndSay(2) << endl;
    return 0;
}