// gcd

class Solution {
public:
    string fractionAddition(string expression) {
        int p = 0;
        int a, b;
        int resa = 0, resb = 1;
        while (p < expression.length()) {
            read_frac(a, b, p, expression);
            calc(resa, resb, a, b);
        }
        return to_string(resa) + "/" + to_string(resb);
    }
    
    void read_frac(int& a, int&b, int& p, const string& e) {
        read_num(a, p, e, 1);
        p ++;
        read_num(b, p, e, 0);
    }
    
    void read_num(int& x, int& p, const string& e, bool fg) {
        int sign = 1;
        x = 0;
        while (p < e.length()) {
            if (e[p] >= '0' && e[p] <= '9') x = x * 10 + e[p] - '0';
            else {
                if (!fg) break;
                if (fg && e[p] == '/') break;
                if (e[p] == '-') sign = -1;
            }
            p ++;
        }
        x *= sign;
    }
    
    void calc(int& resa, int& resb, int a, int b) {
        int g = resb * b / get_gcd(resb, b);
        resa = resa * (g / resb) + a * (g / b);
        resb = g;
        int sign = 1;
        if (resa < 0) sign = -1, resa = -resa;
        if (!resa) {resb = 1;return;}
        g = get_gcd(resa, resb);
        resa /= g;
        resb /= g;
        resa *= sign;
    }
    
    int get_gcd(int a, int b) {
        if (!b) return a;
        return get_gcd(b, a % b);
    }
};