class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int last = 0 - seats.size();
        int res = 0;
        for (int i = 0; i < seats.size(); i ++) 
            if (seats[i]) {
                if (last < 0) res = max(res, i - 1);
                else if (i != last + 1) res = max(res, (i - last - 2) >> 1);
                last = i;
            }
        if (seats.size() != last + 1) res = max(res, (int)seats.size() - last - 2);
        return res + 1;
    }
};