// classic: dynamic median without Self-balancing BST
// two heaps

#include <queue>

class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, greater<int>> min_heap; // classic
    priority_queue<int, vector<int>, less<int>> max_heap;
    MedianFinder() {
        while (!min_heap.empty()) min_heap.pop();
        while (!max_heap.empty()) max_heap.pop();
    }
    
    void addNum(int num) {
        max_heap.push(num);
        int z;
        z = max_heap.top();
        max_heap.pop();
        min_heap.push(z);
        
        
        if (min_heap.size() > max_heap.size()) {
            z = min_heap.top();
            min_heap.pop();
            max_heap.push(z);
        }
    }
    
    double findMedian() {
        if (min_heap.size() == max_heap.size()) {
            return 0.5 * (min_heap.top() + max_heap.top());
        } else {
            return max_heap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */