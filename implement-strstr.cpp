/*kmp or hash(可加和)*/
/*typical*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.length() == 0) return 0; // special judge
        vector<int> p(needle.length(), 0);
        int len = 0;
        for (int i = 1; i < needle.length(); i ++) {
            while (len && needle[len] != needle[i]) len = p[len -1];
            if (needle[len] == needle[i]) len ++;
            p[i] = len;
        }
        len = 0;
        for (int i = 0; i < haystack.length(); i ++) {
            while (len && needle[len] != haystack[i]) len = p[len - 1];
            if (needle[len] == haystack[i]) len ++;
            if (len == needle.length()) return i - len + 1;
        }
        return -1;
    }
};