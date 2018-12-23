/*typical*/
/*nums数组相当于数组模拟链表:https://leetcode.com/problems/find-the-duplicate-number/discuss/72846/My-easy-understood-solution-with-O(n)-time-and-O(1)-space-without-modifying-the-array.-With-clear-explanation.*/
/*一种位运算的方法：https://leetcode.com/problems/find-the-duplicate-number/discuss/72872/O(32*N)-solution-using-bit-manipulation-in-10-lines*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int x = nums[0], y = nums[nums[0]];
        while (x != y) {
            x = nums[x];
            y = nums[nums[y]];
        }
        x = 0;
        while (x != y) {
            x = nums[x];
            y = nums[y];
        }
        return x;
    }
};

int main() {
    int a[] = {1,3,4,2,2};
    vector<int> b(a, a + 5);
    cout << Solution().findDuplicate(b) << endl;
    return 0;
}