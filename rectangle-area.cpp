class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int zax = max(A, E);
        int zay = max(B, F);
        
        int zbx = min(C, G);
        int zby = min(D, H);
        
        int res = (C - A) * (D - B);
        if (zax < zbx && zay < zby) res -= (zbx - zax) * (zby - zay);
        res += (G - E) * (H - F);
        
        return res;
    }
};