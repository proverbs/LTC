class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int lt = -1, rt = arr.size();
        for (int i = 0; i < arr.size(); i ++) 
            if (arr[i] <= x) lt = i;
            else break;
        for (int i = arr.size() - 1; i >= 0; i --)
            if (arr[i] >= x) rt = i;
            else break;
        
        if (lt >= rt) lt = rt - 1;
        deque<int> dq;
        while (k && (lt >= 0 || rt < arr.size())) {
            if (lt < 0) dq.push_back(arr[rt ++]);
            else if (rt >= arr.size()) dq.push_front(arr[lt --]);
            else {
                if (x - arr[lt] <= arr[rt] - x) dq.push_front(arr[lt --]);
                else dq.push_back(arr[rt ++]);
            }
            k --;
        }
        vector<int> res;
        while (!dq.empty()) res.push_back(dq.front()), dq.pop_front();
        return res;
    }
};