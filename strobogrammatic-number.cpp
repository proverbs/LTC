class Solution {
public:
    bool isStrobogrammatic(string num) {
        static int a[5] = {'0', '1', '6', '8', '9'};
        static int b[5] = {'0', '1', '9', '8', '6'};
        int lt = 0, rt = num.length() - 1;
        while (lt < rt) {
            bool fg = false;
            for (int i = 0; i < 5; i ++)
                if (num[lt] == a[i] && num[rt] == b[i]) fg = true;
            if (!fg) return false;
            lt ++;
            rt --;
        }
        if (lt == rt) return num[lt] == '0' || num[lt] == '1' || num[lt] == '8';
        return true;
    }
};