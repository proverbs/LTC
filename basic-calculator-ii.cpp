// expr calc

class Solution {
public:
    int calculate(string s) {
        map<char, int> weight;
        weight['#'] = -1;
        weight['-'] = weight['+'] = 0;
        weight['*'] = weight['/'] = 1;
        stack<char> opt;
        stack<long long> num;
        
        opt.push('#');
        
        long long a, b;
        char c;
        
        int p = 0;
        while (p != s.length()) {
            p = read_space(s, p);
            if (p == s.length()) break;
            if (is_opt(s[p])) {
                if (num.empty()) num.push(0);
                // this should be "while" rather than "if"
                while (weight[opt.top()] >= weight[s[p]]) {
                    b = num.top();
                    num.pop();
                    c = opt.top();
                    opt.pop();
                    a = num.top();
                    num.pop();
                    num.push(calc(a, c, b));
                }
                opt.push(s[p ++]);
            } else {
                pair<int, long long> p_v = get_num(s, p);
                p = p_v.first;
                num.push(p_v.second);
            }
        }
        
        if (num.size() == 0) return 0;
        
        while (num.size() != 1) {
            b = num.top();
            num.pop();
            a = num.top();
            num.pop();
            c = opt.top();
            opt.pop();
            num.push(calc(a, c, b));
        }
        return num.top();
    }
    
    int read_space(const string& s, int p) {
        while (p != s.length() && s[p] == ' ') p ++;
        return p;
    }
    
    pair<int, long long> get_num(const string& s, int p) {
        long long res = 0;
        while (p != s.length() && s[p] >= '0' && s[p] <= '9') {
            res = res * 10 + s[p ++] - '0';
        }
        return make_pair(p, res);
    }
    
    long long calc(long long a, char c, long long b) {
        if (c == '+') return a + b;
        if (c == '-') return a - b;
        if (c == '/') return a / b;
        if (c == '*') return a * b;
        return 0;
    }
    
    bool is_opt(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/';
    }
};