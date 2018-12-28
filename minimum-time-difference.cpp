class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int z = 24 * 60;
        vector<int> ts(z, 0);
        for (int i = 0; i < timePoints.size(); i ++) {
            int x = (timePoints[i][0] - '0') * 10 + timePoints[i][1] - '0';
            x = x * 60 + (timePoints[i][3] - '0') * 10 + timePoints[i][4] - '0';
            ts[x] ++;
        }
        int res = 9999999;
        int last = -9999999;
        for (int i = 0; i < z; i ++)
            for (int j = 0; j < ts[i]; j ++) {
                res = min(res, i - last);
                last = i;
            }
        
        
        for (int i = 0; i < z; i ++) 
            if (ts[i]) {
                res = min(res, (i + z - last) % z);
                break;
            }
        return res;
    }
};