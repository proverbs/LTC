class Solution {
public:
    string solveEquation(string equation) {
        int mid = 0;
        while (equation[mid] != '=') mid ++;
        pair<int, int> lt = calc(equation.substr(0, mid) + "+");
        pair<int, int> rt = calc(equation.substr(mid + 1) + "+");
        
        int left = lt.first - rt.first;
        int right = rt.second - lt.second;
        // cout << left << "  " << right << endl;
        if (left == 0) {
            if (right == 0) return "Infinite solutions";
            else return "No solution";
        } else {
            return "x=" + to_string(right / left);
        }
    }
    
    pair<int, int> calc(string e) {
        pair<int, int> res = {0, 0};
        int num = 0;
        int fg = 1;
        for (int i = 0; i < e.length(); i ++) {
            if (e[i] >= '0' && e[i] <= '9') num = num * 10 + e[i] - '0';
            else {
                if (e[i] == 'x') {
                    if (num == 0) {
                        if (i - 1 >= 0 && e[i - 1] == '0') res.first += 0; // 0x
                        else res.first += 1 * fg;
                    }
                    else res.first += num * fg;
                } else if (e[i] == '+') {
                    res.second += num * fg;
                    fg = 1;
                } else if (e[i] == '-') {
                    res.second += num * fg;
                    fg = -1;
                }
                num = 0;
            }
        }
        return res;
    }
};