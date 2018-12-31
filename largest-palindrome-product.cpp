class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1) return 9;
        long long mx = pow(10, n) - 1;
        long long cf = mx;
        while (true) {
            long long num = palindrome(mx);
            if (check(num, cf)) return num % 1337;
            mx --;
        }
    }
    
    long long palindrome(long long x) {
        string s;
        int y = x;
        while (x) {
            s.push_back(x % 10 + '0');
            x /= 10;
        }
        s = to_string(y) + s;
        sscanf(s.c_str(), "%lld", &x);
        return x;
    }
    
    bool check(long long num, long long mx) {
        cout << num << " " << mx << endl;
        while (mx * mx >= num) {
            if (num % mx == 0) return true;
            mx --;
        }
        return false;
    }
};