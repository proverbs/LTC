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


/**
 * a better version, however, the hash function only works for this problem
*/
class Solution {
public:
    const static long long MOD = 1000000007LL;
    string longestPalindrome(string s) {
        int n = s.length();
        int nn = n * 2 + 1;
        vector<long long> factor(nn, 0);
        factor[0] = 1LL;
        for (int i = 1; i < nn; i ++) {
            factor[i] = factor[i - 1] * 27 % MOD;
        }
        
        vector<long long> hash_lt(nn, 0);
        hash_lt[0] = 0;
        for (int i = 1; i < nn - 1; i ++) {
            if (i & 1) hash_lt[i] = (hash_lt[i - 1] + factor[i] * (s[i >> 1] - 'a' + 1)) % MOD;
            else hash_lt[i] = hash_lt[i - 1];
        }
        
        vector<long long> hash_rt(nn, 0);
        hash_rt[nn - 1] = 0;
        for (int i = nn - 2; i >= 0; i --) {
            if (i & 1) hash_rt[i] = (hash_rt[i + 1] + factor[nn - 1 - i] * (s[i >> 1] - 'a' + 1)) % MOD;
            else hash_rt[i] = hash_rt[i + 1];
        }
        
        int res_center = -1;
        int res_radium = -1;
        
        for (int i = 0; i < nn; i ++) {
            int lt = 1, rt = min(i, nn - i);
            while (lt <= rt) {
                int len = lt + rt >> 1;
                if (check(hash_lt, hash_rt, i, len, factor, nn)) {
                    if (len > res_radium) {
                        res_radium = len;
                        res_center = i;
                    }
                    lt = len + 1;
                } else {
                    rt = len - 1;
                }
            }
        }
        
        string res;
        for (int i = res_center - res_radium + 1; i <= res_center + res_radium - 1; i ++) {
            if (i & 1) res.push_back(s[i >> 1]);
        }
        return res;
    }
    
    bool check(vector<long long>& hash_lt, vector<long long>& hash_rt, int i, int len, vector<long long>& factor, int nn) {
        long long vlt = hash_lt[i], vrt = hash_rt[i];
        if (i - len >= 0) vlt = ((vlt - hash_lt[i - len]) % MOD + MOD) % MOD;
        if (i + len < nn) vrt = ((vrt - hash_rt[i + len]) % MOD + MOD) % MOD;
        int dt = i - (nn - i - 1);
        if (dt < 0) vlt = (vlt * factor[-dt]) % MOD;
        else vrt = (vrt * factor[dt]) % MOD;
        return vrt == vlt;
    }
};