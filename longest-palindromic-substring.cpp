/*hash */
// there could be many substring with the same hash
// then use DP or suffix array

#include <vector>
#include <iostream>
#include <string>

const int MOD = 19999;

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() == 0) return s;
        
        vector<int> e;
        e.resize(s.length());
        e[0] = 1;
        for (int i = 1; i < s.length(); i++) {
            e[i] = e[i - 1] * 26 % MOD;
        }
        
        vector<int> hash1, hash2;
        hash1.resize(s.length());
        hash2.resize(s.length());
        hash1[0] = s[0] - 'a';
        for (int i = 1; i < s.length(); i++) {
            hash1[i] = (hash1[i - 1] * 26 + s[i] - 'a') % MOD;
            // cout << i << " " << hash1[i] << endl; 
        }
        hash2[s.length() - 1] = s[s.length() - 1] - 'a';
        for (int i = s.length() - 2; i >= 0; i--) {
            hash2[i] = (hash2[i + 1] * 26 + s[i] - 'a') % MOD;
            // cout << i << " " << hash2[i] << endl; 
        }
        // odd
        int res_mid = 0, res_len = 1;
        for (int i = 0; i < s.length(); i++) {
            int lt = 1;
            int rt = min(int(s.length()) - i, i + 1);
            while (lt <= rt) {
                int mid = (lt + rt) >> 1;
                if (check(i, mid, hash1, hash2, s, e[mid - 1])) {
                    if (mid > res_len) {
                        res_len = mid;
                        res_mid = i;
                    }
                    lt = mid + 1;
                }
                else {
                    rt = mid - 1;
                }
            }
        }
        string res1 = s.substr(res_mid - res_len + 1, 2 * res_len - 1);
        // even
        res_mid = -1;
        res_len = res1.length() / 2;
        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] != s[i + 1]) continue;
            int lt = 1;
            int rt = min(int(s.length()) - i - 1, i + 1);
            while (lt <= rt) {
                int mid = (lt + rt) >> 1;
                if (check1(i, mid, hash1, hash2, s, e[mid - 1])) {
                    if (mid > res_len) {
                        res_len = mid;
                        res_mid = i;
                    }
                    lt = mid + 1;
                }
                else {
                    rt = mid - 1;
                }
            }
        }
        string res2 = "";
        if (res_mid != -1) res2 = s.substr(res_mid - res_len + 1, 2 * res_len);
        
        return res1.length() > res2.length() ? res1 : res2;
    }

    bool check(int mid, int len, vector<int>& hash1, vector<int>& hash2, string& s, int e) {
        if ((hash1[mid + len - 1] - (hash1[mid] * e) % MOD + MOD) % MOD == (hash2[mid - len + 1] - (hash2[mid] * e) % MOD + MOD) % MOD) {
            for (int i = 1; i < len; i++) {
                if (s[mid - i] != s[mid + i]) return false;
            }
            return true;
        }
        //cout << mid << "  " << len << endl;
        return false;
    }


    bool check1(int mid, int len, vector<int>& hash1, vector<int>& hash2, string& s, int e) {
        if ((hash1[mid + len] - (hash1[mid + 1] * e) % MOD + MOD) % MOD == (hash2[mid - len + 1] - (hash2[mid] * e) % MOD + MOD) % MOD) {
            for (int i = 1; i < len; i++) {
                if (s[mid - i] != s[mid + i + 1]) return false;
            }
            return true;
        }
        //cout << mid << "  " << len << endl;
        return false;
    }
};

int main() {
    string a = "bddtattarrattatdda";
    cout << Solution().longestPalindrome(a) << endl;
    return 0;
}