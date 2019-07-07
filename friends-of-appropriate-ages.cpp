class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int res = 0;
        int n = ages.size();
        vector<int> cnt_age(121, 0), sum_cnt(121, 0);
        for (int age: ages) cnt_age[age] ++;
        for (int i = 1; i <= 120; i ++) sum_cnt[i] = sum_cnt[i - 1] + cnt_age[i];
        for (int age: ages) {
            // first 2 requirements
            int lt = age / 2 + 7;
            int rt = age;
            if (lt >= rt) continue;
            // the third requirement
            if (age < 100) rt = min(100, rt);
            res += sum_cnt[rt] - sum_cnt[lt];
            if (rt == age) res -= 1;
        }
        return res;
    }
};