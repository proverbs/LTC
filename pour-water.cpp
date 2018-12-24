// O(vlogn)
class Solution {
public:
    struct PR {
        int val, idx;
        PR(int idx, int val) : idx(idx), val(val) {}
    };
    
    class Compare {
    public:
        bool operator() (const PR &a, const PR &b) {
            if (a.val == b.val) return a.idx < b.idx;
            return a.val > b.val;
        }
    };
    
    priority_queue<PR, vector<PR>, Compare> lt, rt;
    int plt, prt;
    
    vector<int> pourWater(vector<int>& heights, int V, int K) {
        plt = K - 1;
        while (plt >= 0 && heights[plt] <= heights[plt + 1]) {
            lt.push(PR(plt, heights[plt]));
            plt --;
        }
        prt = K + 1;
        while (prt < heights.size() && heights[prt] <= heights[prt - 1]) {
            rt.push(PR(-prt, heights[prt]));
            prt ++;
        }
        
        while (V --) {
            if (!lt.empty() && lt.top().val < heights[K]) {
                PR z = lt.top();
                z.val += 1;
                heights[z.idx] += 1;
                lt.pop();
                lt.push(z);
            } else if (!rt.empty() && rt.top().val < heights[K]) {
                PR z = rt.top();
                z.val += 1;
                heights[-z.idx] += 1;
                rt.pop();
                rt.push(z);
            } else {
                heights[K] ++;
            } 
            while (plt >= 0 && heights[plt] <= heights[plt + 1]) {
                lt.push(PR(plt, heights[plt]));
                plt --;
            }
            while (prt < heights.size() && heights[prt] <= heights[prt - 1]) {
                rt.push(PR(-prt, heights[prt]));
                prt ++;
            }
            // cout << lt.size() << " " << rt.size() << endl;
        }
        
        return heights;
    }
    
};