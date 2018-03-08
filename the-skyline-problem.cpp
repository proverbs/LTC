/*scan line*/
/*细节很多*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    struct PX {
        int x, y, fg;
        PX(int a, int b, int c) : x(a), y(b), fg(c) {}
    };
    vector<pair<int, int> > getSkyline(vector<vector<int> >& buildings) {
        vector<pair<int, int> > res;
        multiset<int> st;
        st.insert(0);
        vector<PX> px;
        for (int i = 0; i < buildings.size(); i ++) {
            px.push_back(PX(buildings[i][0], buildings[i][2], 1));
            px.push_back(PX(buildings[i][1], buildings[i][2], -1));
        }
        int sz = buildings.size();
        sort(px.begin(), px.end(), cmp);
        sz *= 2;
        int lmx = 0;
        for (int i = 0, mx; i < sz; i ++) {
            if (px[i].fg == 1) {
                st.insert(px[i].y);
            } else {
                st.erase(st.find(px[i].y)); // 直接erase一个值，可能会删除多个值
            }
            if (i != sz - 1 && px[i + 1].x == px[i].x) continue; // 非常细节
            
            mx = *st.rbegin();
            if (mx != lmx) {
                res.push_back(make_pair(px[i].x, mx));
                lmx = mx;
            }
        }
        return res;
    }

    static bool cmp(const PX& a, const PX& b) {
        if (a.x == b.x) return a.fg > b.fg; // 非常细节
        return a.x < b.x;
    }
};

int main() {
    vector<int> v;
    v.push_back(0);v.push_back(2);v.push_back(3);
    vector<vector<int> > s;
    s.push_back(v);
    v[0] = 2; v[1] = 5; v[2] = 5;
    s.push_back(v);
    cout << Solution().getSkyline(s).size() << endl;
    return 0;
}