/*stack*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
       stack<char> stk;
       for (int i = 0; i < s.length(); i ++) {
           if (!stk.empty() && isMatch(stk.top(), s[i])) stk.pop();
           else stk.push(s[i]);
       }
       return stk.size() == 0;
    }

    bool isMatch(char x, char y) {
        return (x == '(' && y == ')') || (x == '[' && y == ']') || (x == '{' && y == '}');
    }
};

int main() {
    cout << Solution().isValid("(())") << endl;
    return 0;
}