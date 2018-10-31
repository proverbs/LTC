import java.util.ArrayList;
import java.util.List;

class Solution {

    private void rangeAdd(List<String> res, int lt, int rt) {
        if (lt == rt) {
            res.add(String.valueOf(lt));
        } else {
            res.add(String.valueOf(lt) + "->" + String.valueOf(rt));
        }
    }

    public List<String> findMissingRanges(int[] nums, int lower, int upper) {
        List<String> res = new ArrayList<>();
        if (nums.length != 0 && nums[0] > lower) {
            rangeAdd(res, lower, nums[0] - 1);
        }
        for (int i = 0; i < nums.length - 1; i ++) {
            if (nums[i] >= upper) break;
            if (nums[i] != nums[i + 1] && nums[i] + 1 != nums[i + 1]) {
                rangeAdd(res, nums[i] + 1, nums[i + 1] - 1);
            }
        }
        if (nums.length != 0 && nums[nums.length - 1] < upper) {
            rangeAdd(res, nums[nums.length - 1] + 1, upper);
        }
        if (nums.length == 0) {
            rangeAdd(res, lower, upper);
        }
        return res;
    }
}