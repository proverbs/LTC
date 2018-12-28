// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int lt = 1, rt = n, res;
        while (lt <= rt) {
            int mid = (long long)lt + rt >> 1;
            if (isBadVersion(mid)) rt = mid - 1, res = mid;
            else lt = mid + 1;
        }
        return res;
    }
};