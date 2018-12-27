// two pointers(sorted in ascending order)

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lt = 0, rt = numbers.size() - 1;
        while (lt != rt) {
            while (numbers[rt] + numbers[lt] > target) rt --;
            if (numbers[rt] + numbers[lt] == target) break;
            lt ++;
        }
        vector<int> res;
        res.push_back(lt + 1);
        res.push_back(rt + 1);
        return res;
    }
};