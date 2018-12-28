// use stack to simulate '(' and ')'

class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        char opt[4] = {'+', '-', '*', '/'};
        for (int i = 0; i < 4; i ++) {
            for (int j = 0; j < 4; j ++) {
                if (i == j) continue;
                for (int k = 0; k < 4; k ++) {
                    if (k == j || k == i) continue;
                    for (int p = 0; p < 4; p ++) {
                        if (p == k || p == j || p == i) continue;
                        // enumerator operator
                        for (int ii = 0; ii < 4; ii ++)
                            for (int jj = 0; jj < 4; jj ++)
                                for (int kk = 0; kk < 4; kk ++) {
                                    deque<double> dq_nums({nums[i], nums[j], nums[k], nums[p]});
                                    deque<char> dq_opts({opt[ii], opt[jj], opt[kk], '#'});
                                    if (dfs(dq_nums, dq_opts, stack<double>(), stack<char>())) return true;
                                }
                        
                    }
                }
            }
        }
        return false;
    }
    
    bool dfs(deque<double> nums, deque<char> opts, stack<double> ns, stack<char> op) {
        if (nums.empty()) {
            op.pop();
            while (ns.size() != 1) {
                double y = ns.top();
                ns.pop();
                double x = ns.top();
                ns.pop();
                char c = op.top();
                op.pop();
                ns.push(calc(x, c, y));
            }
            return fabs(ns.top() - 24) < 1e-5;
        }
        ns.push(nums.front());
        nums.pop_front();
        char o = opts.front();
        opts.pop_front();
        
        op.push(o);
        if (dfs(nums, opts, ns, op)) return true;
        op.pop();
        
        for (int i = 0; i < op.size(); i ++) {
            // calculate using i + 1 operators
            double y = ns.top();
            ns.pop();
            double x = ns.top();
            ns.pop();
            char c = op.top();
            op.pop();
            
            ns.push(calc(x, c, y));
            op.push(o);
            if (dfs(nums, opts, ns, op)) return true;
            op.pop();
        }
        
        return false;
    }
    
    double calc(double x, char c, double y) {
        if (c == '+') return x + y;
        else if (c == '-') return x - y;
        else if (c == '*') return x * y;
        else {
            if (y == 0) return 999999;
            else return x / y;
        }
    }
};