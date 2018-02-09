/*intelligence, two pointer*/
/*
思路：
（1）首先，两边都存在比自己高的点，一定不会有最大面积。所以，删除符合条件的点，剩余点形状为单峰。
（2）考虑用两个指针，从两侧向内收缩：每次移动那个指针呢？用排除法，如果移动指针lt，需要保证lt接下来不会再构成更大面积。
因为lt和rt中较短的那一个再也不会构成更大的面积（因为山峰性，他成为所有面积的短板），所以移动较短的那一个。
（3）优化：不需要删点也不影响算法流程（可以证明，对于未删除的点，移动顺序是不变的）
*/
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int lt = 0, rt = height.size() - 1;
        int mz = min(height[lt], height[rt]) * (rt - lt);
        while (lt < rt) {
            if (height[lt] < height[rt]) lt ++;
            else rt --;
            mz = max(mz, min(height[lt], height[rt]) * (rt - lt));
        }
        return mz;
    }
};