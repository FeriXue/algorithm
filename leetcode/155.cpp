#include <iostream>
#include <stack>
#include <limits.h>

using namespace std;

class MinStack {
public:

    MinStack() {
        mi.push(INT_MAX);
    }
    
    void push(int x) {
        x_stack.push(x);
        mi.push(min(x, mi.top()));
    }
    
    void pop() {
        x_stack.pop(); 
        mi.pop();
    }
    
    int top() {
        return x_stack.top();
    }
    
    int getMin() {
        return mi.top();
    }

private:
    stack<int> x_stack;
    stack<int> mi;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
