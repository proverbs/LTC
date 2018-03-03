/*two pointer*/

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<char> stk;
        int maxlen = 0;
        int pline = 0, tmaxlen = 0;
        for (int i = 0; i < s.length(); ) {
            while (!stk.empty() && stk.top() == '(' && s[i] == ')') {
                stk.pop();
                i ++;
                tmaxlen += 2;
            }
            maxlen = max(maxlen, tmaxlen);
            if (pline > stk.size()) tmaxlen = 0;
            pline = stk.size();
           
            if (i < s.length()) stk.push(s[i++]);
        }
        return maxlen;
    }
};

int main() {
    cout << Solution().longestValidParentheses("()(())") << endl;
    return 0;
}