// if subsequence means a subarray which is continous
// convert sum of widths to: sum(max) - sum(min). consider subarrays whose maximum is A[i].

class Solution {
public:
    int sumSubseqWidths(vector<int>& A) {
        
        // calc sum max
        vector<int> xs;
        xs.push_back(22222);
        for (int a: A) xs.push_back(a);
        xs.push_back(22222);
        int n = xs.size();
        
        vector<int> lt(n, 0), rt(n, 0);
        
        stack<int> stk;
        stk.push(0);
        for (int i = 1; i < n - 1; i ++) {
            while (xs[stk.top()] <= xs[i]) stk.pop();
            lt[i] = stk.top();
            stk.push(i);
        }
        
        while (!stk.empty()) stk.pop();
        stk.push(n - 1);
        for (int i = n - 2; i >= 1; i --) {
            while (xs[stk.top()] < xs[i]) stk.pop();
            rt[i] = stk.top();
            stk.push(i);
        }
        
        long long sum_max = 0;
        long long mod = 1e9 + 7;
        for (int i = 1; i < n - 1; i ++) {
            sum_max += (i - lt[i]) * (rt[i] - i) * xs[i];
            sum_max %= mod;
        }
        
        // calc sum min
        xs[0] = xs[n - 1] = -22222;
        
        while (!stk.empty()) stk.pop();
        stk.push(0);
        for (int i = 1; i < n - 1; i ++) {
            while (xs[stk.top()] >= xs[i]) stk.pop();
            lt[i] = stk.top();
            stk.push(i);
        }
        
        while (!stk.empty()) stk.pop();
        stk.push(n - 1);
        for (int i = n - 2; i >= 1; i --) {
            while (xs[stk.top()] >= xs[i]) stk.pop();
            rt[i] = stk.top();
            stk.push(i);
        }
        
        long long sum_min = 0;
        for (int i = 1; i < n - 1; i ++) {
            sum_min += (i - lt[i]) * (rt[i] - i) * xs[i];
            sum_min %= mod;
        }
        
        return (sum_max - sum_min + mod) % mod;
    }
};


// if subsequence means a subset
// the same method
class Solution {
public:
    int sumSubseqWidths(vector<int>& A) {
        int mod = 1e9 + 7;
        int n = 20001;
        vector<int> bk(n, 0);
        for (int a: A) bk[a] ++;
        long long sum = 0;
        
        long long sum_max = 0;
        for (int i = 1; i < n; i ++) {
            if (!bk[i]) continue;
            sum_max += fast_power(2, sum) * (fast_power(2, bk[i]) - 1) % mod * i % mod;
            sum += bk[i];
        }
        
        long long sum_min = 0;
        sum = 0;
        for (int i = n - 1; i >= 1; i --) {
            if (!bk[i]) continue;
            sum_min += fast_power(2, sum) * (fast_power(2, bk[i]) - 1) % mod * i % mod;
            sum += bk[i];
        }
        
        return ((sum_max - sum_min) % mod + mod) % mod;
    }
    
    long long fast_power(long long x, long long y) {
        static long long mod = 1e9 + 7;
        long long res = 1LL;
        while (y) {
            if (y & 1LL) res = res * x % mod;
            x = x * x % mod;
            y >>= 1LL;
        }
        return res;
    }
};