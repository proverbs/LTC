/*stack + dp*/

#include <stack>
#include <iostream>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        stk = new stack<P>;
    }
    
    void push(int x) {
        if (stk->empty()) stk->push(P(x, x));
        else stk->push(P(x, min(x, stk->top().minval)));
    }
    
    void pop() {
        stk->pop();
    }
    
    int top() {
        return stk->top().val;
    }
    
    int getMin() {
        return stk->top().minval;
    }
private:
    struct P {
        int val, minval; // minval表示当前位置向下的所有元素中最小的元素（非常巧妙）
        P(int x, int y) : val(x), minval(y) {}
    };
    stack<P>* stk;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */