class MaxStack {
public:
    /** initialize your data structure here. */
    
    struct Node {
        int x;
        Node *next;
        Node(int x, Node *next) : x(x), next(next) {}
    };
    
    class Compare {
    public:
        bool operator() (const Node *ia, const Node *ib) {
            return ia->x <= ib->x; // <=: make the recently added closer to the top
        }
    };
    
    priority_queue<Node*, vector<Node*>, Compare> pq;
    Node *tp;
    unordered_set<Node*> del; // lazy remove
    
    MaxStack() {
        tp = new Node(0, NULL);
    }
    
    void push(int x) {
        tp = new Node(x, tp);
        pq.push(tp);
    }
    
    int pop() {
        while (del.count(tp)) {
            del.erase(tp);
            tp = tp->next;
        }
        
        del.insert(tp);
        int res = tp->x;
        tp = tp->next;
        
        return res;
    }
    
    int top() {
        while (del.count(tp)) {
            del.erase(tp);
            tp = tp->next;
        }
        return tp->x;
    }
    
    int peekMax() {
        while (del.count(pq.top())) {
            del.erase(pq.top());
            pq.pop();
        }
        return pq.top()->x;
    }
    
    int popMax() {
        while (del.count(pq.top())) {
            del.erase(pq.top());
            pq.pop();
        }
        int res = pq.top()->x;
        del.insert(pq.top());
        pq.pop();
        return res;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack obj = new MaxStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.peekMax();
 * int param_5 = obj.popMax();
 */