import java.util.Stack;

// stack
class Solution {

    private int checkOperator(String a) {
        if (a.charAt(0) == '+') return 1;
        if (a.charAt(0) == '-') return 2;
        if (a.charAt(0) == '*') return 3;
        if (a.charAt(0) == '/') return 4;
        return 0;
    }

    public int evalRPN(String[] tokens) {
        Stack<Integer> stk = new Stack<>();
        for (int i = 0; i < tokens.length; i ++) {
            boolean fg = false;
            if (tokens[i].length() == 1) {
                int c = checkOperator(tokens[i]);
                if (c > 0) {
                    int b = stk.pop();
                    int a = stk.pop();
                    if (c == 1) stk.push(a + b);
                    else if (c == 2) stk.push(a - b);
                    else if (c == 3) stk.push(a * b);
                    else stk.push(a / b);
                    fg = true;
                }
            } 
            if (!fg) {
                stk.push(Integer.parseInt(tokens[i]));
            }
        }
        return stk.pop();
    }
}