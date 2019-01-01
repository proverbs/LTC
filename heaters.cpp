// binary search the result

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int lt = 0, rt = 1e9, res;
        while (lt <= rt) {
            int mid = lt + rt >> 1;
            if (check(houses, heaters, mid)) res = mid, rt = mid - 1;
            else lt = mid + 1;
        }
        return res;
    }
    
    bool check(vector<int>& ho, vector<int>& he, int r) { // O(n) check
        int nht = 0;
        for (int i = 0; i < ho.size() && nht < he.size(); i ++) {
            while (nht < he.size() && (ho[i] < he[nht] - r || ho[i] > he[nht] + r)) nht ++;
        }
        return nht < he.size();
    }
};