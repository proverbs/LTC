class Solution {
public:
    string dw[3] = {"Thousand", "Million", "Billion"};
    string gw[10] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    string sw[10] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string swx[10] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    
    string numberToWords(int num) {
        if (num == 0) return "Zero"; // special judge
        
        string res = "";
        int cnt = 0;
        while (num) {
            string t = interpret(num % 1000);
            if (t.length() > 0) { // special judge
                if (cnt > 0) res = t + " " + dw[cnt - 1] + " " + res;
                else res = t + " " + res;
            }
            cnt ++;
            num /= 1000;
        }
        while (res[res.length() - 1] == ' ') {
            res = res.substr(0, res.length() - 1);
        }
        return res;
    }
    
    string interpret(int x) {
        string res = "";
        if (x >= 100) {
            res += gw[x / 100] + " Hundred ";
            x %= 100;
        }
        
        if (x / 10 == 1) {
            res += sw[x % 10];
        } else {
            if (x / 10 > 1) {
                res += swx[x / 10] + " ";
            }
            res += gw[x % 10] + " ";
        }
        while (res[res.length() - 1] == ' ') {
            res = res.substr(0, res.length() - 1);
        }
        return res;
    }
};