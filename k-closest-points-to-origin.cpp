// Max Heap

class Solution {
public:
    class Compare {
    public:
        static int dis2(const vector<int>& a) {
            return a[0] * a[0] + a[1] * a[1];
        }
        bool operator() (const vector<int>& a, const vector<int> &b) {
            return dis2(a) < dis2(b);
        }
    };
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> res;
        priority_queue<vector<int>, vector<vector<int>>, Compare> pq;
        for (const vector<int>& point: points) {
            if (pq.size() < K) pq.push(point);
            else {
                const vector<int>& tp = pq.top();
                if (Compare::dis2(tp) > Compare::dis2(point)) {
                    pq.pop();
                    pq.push(point);
                }
            }
        }
        while (!pq.empty()) {
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
};
