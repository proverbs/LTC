// slide window
import java.util.Map;

class Solution {
    public int totalFruit(int[] tree) {
        int[] num = new int[2];
        int[] pos = new int[2];
        int sz = 0;
        int lt = 0;
        int ans = 0;
        for (int i = 0; i < tree.length; i ++) {
            if (sz == 2) {
                if (tree[i] == num[0]) {
                    pos[0] = i;
                } else if (tree[i] == num[1]) {
                    pos[1] = i;
                } else {
                    lt = Math.min(pos[0], pos[1]) + 1;
                    if (num[0] == tree[lt - 1]) {
                        num[0] = tree[i];
                        pos[0] = i;
                    } else {
                        num[1] = tree[i];
                        pos[1] = i;
                    }
                }
            } else {
                boolean fg = false;
                if (sz == 1) {
                    if (tree[i] == num[0]) {
                        pos[0] = i;
                        fg = true;
                    } 
                }
                if (!fg) {
                    num[sz] = tree[i];
                    pos[sz] = i;
                    sz ++;
                }
            }
            ans = Math.max(ans, i - lt + 1);
        }
        return ans;
    }
}