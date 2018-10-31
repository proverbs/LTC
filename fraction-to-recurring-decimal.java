import java.util.HashMap;
import java.util.Map;

import org.omg.CORBA.DynEnum;

class Solution {
    
    String s = new String();
    Map<Long, Integer> mp = new HashMap<>();

    public String fractionToDecimal(int numerator, int denominator) {
        long num = numerator;
        long den = denominator;
        boolean fg = true;
        if (num < 0) {
            num = -num;
            fg = !fg;
        }
        if (den < 0) {
            den = -den;
            fg = !fg;
        }
        long rt = num / den;
        s = String.valueOf(rt);
        num = num % den;
        if (num != 0) {
            s = s + ".";
            while (num != 0) {
                int pos = mp.getOrDefault(num, -1);
                if (pos == -1) {
                    rt = num * 10 / den;
                    s += String.valueOf(rt);
                    mp.put(num, s.length() - 1);
                    num = num * 10 % den;
                } else {
                    s = s.substring(0, pos) + "(" + s.substring(pos) + ")";
                    break;
                }
            }
        }
        if (!fg && !s.equals("0")) s = "-" + s;
        return s;
    }
}