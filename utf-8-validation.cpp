class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int nxt = -1;
        for (int i = 0; i < data.size(); i ++) {
            int num = calc(data[i]);
            if (num > 4) return false;
            if (nxt > 0) {
                if (num != 1) return false;
                nxt --;
            } else {
                if (num == 1) return false;
                nxt = num - 1;
            }
        }
        if (nxt > 0) return false;
        return true;
    }
    
    int calc(int x) {
        int res = 0;
        for (int i = 7; i >= 0; i --) {
            if (x & (1 << i)) res ++;
            else break;
        }
        cout << res << endl;
        return res;
    }
};