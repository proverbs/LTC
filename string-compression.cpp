// O(n) in-place

class Solution {
public:
    int compress(vector<char>& chars) {
        if (chars.size() == 0) return 0;
        chars.push_back('~');
        int sz = 1;
        int cont = 1;
        for (int i = 1; i < chars.size(); i ++) {
            if (chars[i - 1] != chars[i]) {
                if (cont == 1) {
                    chars[sz ++] = chars[i];
                    continue;
                }
                int lt = sz;
                while (cont) {
                    chars[sz ++] = cont % 10 + '0';
                    cont /= 10;
                }
                reverse(chars.begin() + lt, chars.begin() + sz);
                chars[sz ++] = chars[i];
                cont = 1;
            } else cont ++;
        }
        sz --;
        while (chars.size() != sz) chars.pop_back();
        return sz;
    }
};