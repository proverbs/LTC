// 参考罗马数字wiki：https://zh.wikipedia.org/wiki/%E7%BD%97%E9%A9%AC%E6%95%B0%E5%AD%97*/
// 罗马数字转阿拉伯数字：从后往前，判断相邻两个数的大小，从而决定加、减
// 阿拉伯数字转罗马数字：貌似只能打表


#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        mp['#'] = 0;
        int res = 0;
        char lastchar = '#';
        for (int i = s.length() - 1; i >= 0; i --) {
            if (mp[lastchar] <= mp[s[i]]) res += mp[s[i]];
            else res -= mp[s[i]];
            lastchar = s[i];
        }
        return res;
    }
};


class RESolution {
public:
    string intToRoman(int num) {
        string M[] = {"", "M", "MM", "MMM"};
        string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        return M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[num%10];
    }
};

int main() {
    string s = "XIV";
    cout << Solution().romanToInt(s) << endl;
    cout << RESolution().intToRoman(Solution().romanToInt(s)) << endl;
    return 0;
}