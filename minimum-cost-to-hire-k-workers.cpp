// typical: priority_queue + sort + comparator
// enumerate all ratios, then how to calculate the minimum cost?
// maintain workers whose ratios are less than current ratio, and select K workers with the least quality

class Solution {
public:
    class PX {
    public:
        int q, w;
        PX(int q, int w) {
            this->q = q;
            this->w = w;
        }
    };
    
    class Compare { // IMPORTANT
    public:
        bool operator() (const PX &a, const PX &b) {
            return a.q < b.q;
        }
    };
    
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        vector<PX> px;
        for (int i = 0; i < wage.size(); i ++) {
            px.push_back(PX(quality[i], wage[i]));
        }
        sort(px.begin(), px.end(), cmp);
        
        priority_queue<PX, vector<PX>, Compare> pqk;
        
        int sumq = 0;
        for (int i = 0; i < K; i ++) {
            sumq += px[i].q;
            pqk.push(px[i]);
        }
        double res = 1.0 * px[K - 1].w / px[K - 1].q * sumq;
        
        for (int i = K; i < px.size(); i ++) {
            sumq -= pqk.top().q;
            pqk.pop();
            pqk.push(px[i]);
            sumq += px[i].q;
            res = min(res, 1.0 * px[i].w / px[i].q * sumq);
        }
        
        return res;
    }
    
    static bool cmp(const PX &a, const PX &b) { // IMPORTANT
        return 1.0 * a.w / a.q < 1.0 * b.w / b.q;
    }
};