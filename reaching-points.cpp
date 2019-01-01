// thinking of transform (tx,ty) to (sx,sy)
// many corner cases
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if (tx == sx && sy == ty) return true;
        if (tx == 0 || ty == 0) return false;
        if (tx == sx && ty > sy && (ty - sy) % sx == 0) return true;
        if (ty == sy && tx > sx && (tx - sx) % sy == 0) return true;
        
        if (tx <= sx && ty <= sy) return false;
        
        if (tx > ty) return reachingPoints(sx, sy, tx % ty, ty);
        else if (tx < ty) return reachingPoints(sx, sy, tx, ty % tx);
        return false;
    }
};