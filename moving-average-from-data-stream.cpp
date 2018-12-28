class MovingAverage {
public:
    deque<int> dq;
    int cap;
    int sum;
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        cap = size;
        sum = 0;
        dq.clear();
    }
    
    double next(int val) {
        dq.push_back(val);
        sum += val;
        if (dq.size() == cap + 1) sum -= dq.front(), dq.pop_front();
        return 1.0 * sum / dq.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */