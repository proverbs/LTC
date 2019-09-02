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

/**
 * optimized by store the index in the hashmap
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> cnt;
        int lt = 0, rt = lt;
        int res = 0;
        while (rt < s.length()) {
            while (rt < s.length() && (!cnt.count(s[rt]) || cnt[s[rt]] < lt)) {
                cnt[s[rt]] = rt;
                rt ++;
            }
            res = max(res, rt - lt);
            lt = cnt[s[lt]] + 1;
        }
        return res;
    }
};