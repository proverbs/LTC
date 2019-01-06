class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        // calc sum min
        static long long mod = 1e9 + 7;
        vector<int> xs;
        xs.push_back(-222222);
        for (int a: A) xs.push_back(a);
        xs.push_back(-222222);
        int n = xs.size();
        
        vector<int> lt(n, 0), rt(n, 0);
        
        stack<int> stk;
        stk.push(0);
        for (int i = 1; i < n - 1; i ++) {
            while (xs[stk.top()] >= xs[i]) stk.pop(); // IMPORTANT: with '='
            lt[i] = stk.top();
            stk.push(i);
        }
        
        while (!stk.empty()) stk.pop();
        stk.push(n - 1);
        for (int i = n - 2; i >= 1; i --) {
            while (xs[stk.top()] > xs[i]) stk.pop(); // IMPORTANT: without '=' to avoid duplicates in array. e.g. [1,4,1]
            rt[i] = stk.top();
            stk.push(i);
        }
        
        long long sum_min = 0;
        for (int i = 1; i < n - 1; i ++) {
            sum_min += (long long)(i - lt[i]) * (rt[i] - i) * xs[i];
            sum_min %= mod;
        }
        
        return sum_min;
    }
};