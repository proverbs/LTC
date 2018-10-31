import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;

class Solution {

    private List<Integer> sumw = new ArrayList<>();
    private Random rand = new Random();
    private int sum;
    public Solution(int[] w) {
        sum = 0;
        for (int i = 0; i < w.length; i ++) {
            sum += w[i];
            sumw.add(sum);
        }
    }
    
    public int pickIndex() {
        int ins_pos = Collections.binarySearch(sumw, rand.nextInt(sum) + 1); // nice: Random
        if (ins_pos >= 0) return ins_pos;
        else return -ins_pos - 1;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */