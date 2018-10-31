// binary search
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class RLEIterator {

    List<Integer> a = new ArrayList<>();
    List<Long> suma = new ArrayList<>();
    long sumn = 0;

    public RLEIterator(int[] A) {
        long sum = 0;
        for (int i = 0; i < A.length; i += 2) {
            if (A[i] == 0) continue;
            a.add(A[i + 1]);
            suma.add(sum + A[i]);
            sum += A[i];
        }
    }
    
    public int next(int n) {
        sumn += n;
        int ins_pos = Collections.binarySearch(suma, sumn);
        if (ins_pos >= 0) return a.get(ins_pos);
        else {
            ins_pos = -ins_pos - 1;
            if (ins_pos == a.size()) return -1;
            else return a.get(ins_pos);
        }
    }
}

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator obj = new RLEIterator(A);
 * int param_1 = obj.next(n);
 */