// rectangle->length of sides

class Solution {
public:
    typedef pair<int, int> pr;
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<pr> ps;
        ps.push_back({p1[0], p1[1]});
        ps.push_back({p2[0], p2[1]});
        ps.push_back({p3[0], p3[1]});
        ps.push_back({p4[0], p4[1]});
        
        for (int i = 0; i < 4; i ++)
            for (int j = 0; j < 4; j ++) {
                if (i == j) continue;
                for (int k = 0; k < 4; k ++) {
                    if (i == k || j == k) continue;
                    int p = 6 - i -j - k;
                    bool fg = true;
                    fg &= perpendicular(sub(ps[i], ps[j]), sub(ps[j], ps[k]));
                    fg &= perpendicular(sub(ps[j], ps[k]), sub(ps[k], ps[p]));
                    fg &= perpendicular(sub(ps[k], ps[p]), sub(ps[p], ps[i]));
                    fg &= perpendicular(sub(ps[p], ps[i]), sub(ps[i], ps[j]));
                    if (!fg) continue;
                    if (len2(sub(ps[i], ps[j])) == 0) continue;
                    if (len2(sub(ps[i], ps[j])) == len2(sub(ps[j], ps[k]))) return true;
                }
            }
        return false;
    }
    
    pr sub(const pr& a, const pr& b) {
        return {a.first - b.first, a.second - b.second};
    }
    
    bool perpendicular(const pr& a, const pr& b) {
        return a.first * b.first + a.second * b.second == 0;
    }
    
    int len2(const pr& a) {
        return a.first * a.first + a.second * a.second;
    }
};