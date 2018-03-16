/*dp*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i ++) sum += nums[i];
        if (S > sum || S < -sum) return 0;
        const int DT = 1010;
        vector<int> v(2050, 0);
        vector<vector<int> > dp;
        for (int i = 0; i < nums.size(); i ++) dp.push_back(v);
        dp[0][nums[0] + DT] += 1;
        dp[0][-nums[0] + DT] += 1;
        for (int i = 1; i < nums.size(); i ++) {
            for (int j = -DT; j <= DT; j ++) {
                if (j + DT - nums[i] >= 0 && j + DT - nums[i] < 2050) dp[i][j + DT] += dp[i - 1][j + DT - nums[i]];
                if (j + DT + nums[i] >= 0 && j + DT + nums[i] < 2050) dp[i][j + DT] += dp[i - 1][j + DT + nums[i]];
            }
        }
        return dp[nums.size() - 1][S + DT];
    }
};

int main() {
    int a[] = {2,107,109,113,127,131,137,3,2,3,5,7,11,13,17,19,23,29,47,53};
    vector<int> b(a, a + 20);
    int z = 899;
    cout << Solution().findTargetSumWays(b, z) << endl;
    return 0;
}