/*sort*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct PX {
    string rs;
    string ms;

    PX(string s1, string s2) {
        rs = s1;
        ms = s2;
    }
};

class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        vector<PX> px;
        string ts;
        for (int i = 0; i < strs.size(); i ++) {
            ts = strs[i];
            sort(ts.begin(), ts.end());
            px.push_back(PX(strs[i], ts));
        }
        sort(px.begin(), px.end(), cmp);
        vector<vector<string> > res;
        if (strs.size() == 0) return res;
        // strs.push_back("#");

        vector<string> t;
        for (int i = 1; i < strs.size(); i ++) {
            if (px[i].ms == px[i - 1].ms) t.push_back(px[i - 1].rs);
            else {
                t.push_back(px[i - 1].rs);
                res.push_back(t);
                t.clear();
            }
        }
        t.push_back(px[strs.size() - 1].rs);
        res.push_back(t);
        return res;
    }

    static bool cmp(const PX& a, const PX& b) {
        return a.ms < b.ms;
    }
};

int main() {
    string a[] = {"pal","ugh","boy","sir","nay","sap","zoe","tan","pym","tho","lea","hod","vim","mes","qua","lag","jib","meg","guy","tat","hue","fez","zit","owe","maj","die","dos","bus","dew","yum","gos","deb","pis","mod","poi","hug","ado","dot","fob","tee","oil","bah","wok","sip","eve","dee","bob","cid","han","mit","ram","wis","ark","pry","mys","wag","eng"};
    vector<string> s(a, a + 57);
    cout << Solution().groupAnagrams(s).size() << endl;
    return 0;
}