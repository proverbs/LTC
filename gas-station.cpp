class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int st = 0, ed = 0;
        int sum_gas = 0, sum_cost = 0;
        for (st = 0; st < n; ) {
            if (gas[ed] + sum_gas >= cost[ed] + sum_cost) {
                sum_gas += gas[ed];
                sum_cost += cost[ed];
                ed = (ed + 1) % n;
                if (ed == st) return st;
            } else {
                // actually, we can start from ed directly
                if (st == ed) {
                    st ++;
                    ed ++;
                } else {
                    sum_gas -= gas[st];
                    sum_cost -= cost[st];
                    st ++;
                }
            }
        }
        return -1;
    }
};