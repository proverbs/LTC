// circular queue's size should be (1 + size of ordinary queue)

class MyCircularQueue {
public:
    vector<int> q;
    int lt, rt, sz;
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        q.clear();
        sz = k + 1;
        q.resize(sz);
        lt = 0, rt = 0;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()) return false;
        q[rt] = value;
        rt = (rt + 1) % sz;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty()) return false;
        lt = (lt + 1) % sz;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if (isEmpty()) return -1;
        return q[lt];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if (isEmpty()) return -1;
        return q[(rt - 1 + sz) % sz];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return lt == rt;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return (rt + 1) % sz == lt;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */