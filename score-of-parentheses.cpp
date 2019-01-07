class Solution {
public:
    int scoreOfParentheses(string S) {
        if (S.length() == 0) return 0;
        return dfs(S, 0, S.length() - 1);
    }
    
    int dfs(string&s, int lt, int rt) {
        int cnt = 0, last = lt - 1, sum = 0;
        for (int i = lt; i <= rt; i ++) {
            if (s[i] == '(') cnt ++;
            else if (s[i] == ')') cnt --;
            if (cnt == 0) {
                if (last + 2 == i) sum += 1;
                else sum += 2 * dfs(s, last + 2, i - 1);
                last = i;
            }
        }
        return sum;
    }
};