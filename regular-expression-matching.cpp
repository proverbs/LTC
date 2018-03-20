/*dp，记忆化搜索*/
// 细节比较多，很难一下子想全
// 一个很好的转移方程
// https://leetcode.com/problems/regular-expression-matching/discuss/5684/9-lines-16ms-C++-DP-Solutions-with-Explanations

#include <vector>
#include <string>
#include <iostream>

using namespace std;


class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.length() == 0) return s.length() == 0;

        string pp = "";
        for (int i = 0; i < p.length(); i++) {
            if (p[i] == '*' && (i == 0 || p[i - 1] != '*')) pp.push_back(p[i]);
            if (p[i] != '*') pp.push_back(p[i]);
        }
        p = pp;
        //cout << p << endl;
        
        if (s.length() == 0) return matchBlank(p, 0);
        
        vector<int> v;
        for (int i = 0; i < p.length(); i++) v.push_back(-1);
        vector<vector<int> > mc;
        for (int i = 0; i < s.length(); i++) mc.push_back(v);
        return mc[0][0] = match(s, p, 0, 0, mc); 
    }

    bool match(string& s, string& p, int u, int v, vector<vector<int> >& mc) {
        cout << u << " " << v << endl;
        if (u >= s.length() && v >= p.length()) return 1;
        else if (u >= s.length()) return matchBlank(p, v);
        else if (v >= p.length()) return 0;

        if (mc[u][v] != -1) return mc[u][v];
        
        mc[u][v] = 0;
        if (p[v] != '*') {
            // 与x*匹配成功时，可以匹配，也可以不匹配
            if (p[v] == '.') {
                if (v + 1 < p.length() && p[v + 1] == '*') {
                    if (match(s, p, u + 1, v + 1, mc)) mc[u][v] = 1;
                    else if (match(s, p, u, v + 2, mc)) mc[u][v] = 1;
                }
                else mc[u][v] = match(s, p, u + 1, v + 1, mc);
            }
            else {
                if (s[u] == p[v]) {
                    if (v + 1 < p.length() && p[v + 1] == '*') {
                        if (match(s, p, u + 1, v + 1, mc)) mc[u][v] = 1;
                        else if (match(s, p, u, v + 2, mc)) mc[u][v] = 1;
                    } 
                    else if (match(s, p, u + 1, v + 1, mc)) mc[u][v] = 1;
                }
                else {
                    if (v + 1 < p.length() && p[v + 1] == '*') {
                        if (match(s, p, u, v + 2, mc)) mc[u][v] = 1;
                    } 
                    else mc[u][v] = 0;
                }   
            }
        }
        else {
            if (p[v - 1] != '.') {
                int dt = 0;
                //cout << "fuck2" << endl;
                while (u + dt - 1 < s.length() && s[u + dt - 1] == p[v - 1]) {
                    if (match(s, p, u + dt, v + 1, mc)) return mc[u][v] = 1;
                    dt ++;
                }
            }
            else {// can match any string
                int dt = 0;
                while (u + dt - 1 < s.length()) {
                    if (match(s, p, u + dt, v + 1, mc)) return mc[u][v] = 1;
                    dt ++;
                }
            }
        }
        return mc[u][v];
    }

    bool matchBlank(string& p, int v) {
        for (int i = v; i < p.length(); i++) {
            if (p[i] != '*') {
                if (i + 1 >= p.length() || p[i + 1] != '*') return false;
            }
        }
        return true;
    }
};

int main() {
    cout << Solution().isMatch("a", "ab*a") << endl;
    return 0;
}