class Solution {
public:
    int numJewelsInStones(string J, string S) {
        map<char, bool> j;
        for (int i = 0; i < J.length(); i ++) j[J[i]] = true;
        int res = 0;
        for (int i = 0; i < S.length(); i ++) {
            if (j.count(S[i])) res ++;
        }
        return res;
    }
};