/*set + monotonicity*/

#include <set>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) return 0;
        set<char> st;
        st.insert(s[0]);
        int rt = 1, res = 1;
        for (int i = 0; i < s.length(); i++) {
            while (rt < s.length() && st.count(s[rt]) == 0) {
                st.insert(s[rt]);
                rt += 1;
            }
            res = max(res, rt - i);
            st.erase(s[i]);
            if (rt >= s.length()) break;
        }
        return res;
    }
};

int main() {
    string s = "abcabcbb";
    cout << Solution().lengthOfLongestSubstring(s) << endl;
    return 0;
}