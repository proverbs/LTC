// consider how many numbers are there if the i-th digit is 1

class Solution {
public:
    int countDigitOne(int n) {
        if (n < 0) return 0;
        
        vector<int> nx;
        nx.push_back(1);
        for (int i = 0; i < 10; i ++) nx.push_back(nx.back() * 10);
        
        int sum = 0;
        int res = 0;
        int bk = 0;
        while (n) {
            int x= n % 10;
            if (x == 0) {
                res += (n / 10) * nx[bk];
            } else if (x == 1) {
                res += (n / 10) * nx[bk] + sum + 1;
            } else {
                res += (n / 10 + 1) * nx[bk];
            }
            
            sum = n % 10 * nx[bk] + sum;
            bk ++;
            n /= 10;
        }
        
        return res;
    }
};