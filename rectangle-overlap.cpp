class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int tlx = max(rec1[0], rec2[0]);
        int tly = max(rec1[1], rec2[1]);
        int brx = min(rec1[2], rec2[2]);
        int bry = min(rec1[3], rec2[3]);
        return tlx < brx && tly < bry;
    }
};