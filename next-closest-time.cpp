class Solution {
public:
    int c[4];
    string nextClosestTime(string time) {
        c[0] = time[0] - '0';
        c[1] = time[1] - '0';
        c[2] = time[3] - '0';
        c[3] = time[4] - '0';
        int r = c[0] * 1000 + c[1] * 100 + c[2] * 10 + c[3];
        
        int min_val = 20000;
        
        for (int i = 0; i < 4; i ++) {
            for (int j = 0; j < 4; j ++) {
                int num1 = c[i] * 10 + c[j];
                if (num1 > 23) continue;
                for (int ii = 0; ii < 4; ii ++) {
                    for (int jj = 0; jj < 4; jj ++) {
                        int num2 = c[ii] * 10 + c[jj];
                        if (num2 > 59) continue;
                        // cout << num1 << " " << num2 << endl;
                        if (num1 * 100 + num2 <= r) {
                            min_val = min(10000 + num1 * 100 + num2, min_val);
                        } else {
                            min_val = min(num1 * 100 + num2, min_val);
                        }
                    }
                }
            }
        }
        
        string res = "";
        res.push_back(min_val % 10000 / 1000 + '0');
        res.push_back(min_val % 1000 / 100 + '0');
        res.push_back(':');
        res.push_back(min_val % 100 / 10 + '0');
        res.push_back(min_val % 10 + '0');
        
        return res;
    }
};