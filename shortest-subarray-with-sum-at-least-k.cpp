// typical: mono-increasing deque
// (left, right], deque stores possible left pointers

class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        if (A.size() == 0) return -1;
        
        vector<int> ps(A.size() + 1, 0);
        for (int i = 0; i < A.size(); i ++) ps[i + 1] = ps[i] + A[i];
        
        deque<int> idx;
        idx.push_back(0);
        int res = A.size() + 1;
        
        for (int i = 1; i < ps.size(); i ++) {
            if (A[i - 1] > 0) {
                while (!idx.empty() && ps[i] - ps[idx.front()] >= K) {
                    res = min(res, i - idx.front());
                    idx.pop_front();
                } 
            } else {
                while (!idx.empty() && ps[i] <= ps[idx.back()]) idx.pop_back();
            }
            idx.push_back(i);
        }
        
        if (res <= A.size()) return res;
        return -1;
    }
};