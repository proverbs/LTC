// classic: expression calculation

class Solution {
public:
    stack<int> num;
    stack<char> opr;
    
    int calculate(string s) {
        // init priority, IMPORTANT
        map<char, int> wt;
        wt['+'] = wt['-'] = 1;
        wt['*'] = wt['/'] = 2;
        wt['('] = -1;
        wt[')'] = 0;
        
        int fg = 1;
        char lst = '+';
        for (int i = 0; i < s.length(); i ++) {
            
            if (s[i] >= '0' && s[i] <= '9') {
                lst = s[i];
                int len = 0;
                int x = 0;
                while (i + len < s.length() && s[i + len] >= '0' && s[i + len] <= '9') {
                    x = x * 10 + s[i + len] - '0';
                    len ++;
                }
                i = i + len - 1;
                x *= fg;
                fg = 1;
                num.push(x);
            } else {
                if (s[i] == '-' && wt.count(lst)) {
                    fg = -1;
                } else if (s[i] != ' ') {
                    if (s[i] != '(' && s[i] != ')') lst = s[i];
                    while (!opr.empty() && s[i] != '(' && wt[opr.top()] >= wt[s[i]]) calc();
                    if (!opr.empty() && opr.top() == '(' && s[i] == ')') opr.pop();
                    else opr.push(s[i]);
                }
            }
        }
        while (!opr.empty()) calc();
        
        return num.top();
    }
    
    void calc() {
        puts("f");
        char c = opr.top();
        opr.pop();
        int b = num.top();
        num.pop();
        int a = num.top();
        num.pop();
        // cout << a << c << b << endl;
        if (c == '+') num.push(a + b);
        else if (c == '-') num.push(a - b);
        else if (c == '/') num.push(a / b);
        else if (c == '*') num.push(a * b);
    }
};