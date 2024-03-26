class MinStack {
public:
    stack<int> mins, s;
    MinStack() {
        
    }
    
    void push(int val) {
        if(mins.empty() || mins.top() >= val)
            mins.push(val);

        s.push(val);
    }
    
    void pop() {
        if(mins.size() && mins.top() == s.top())
            mins.pop();

        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return mins.top();
    }
};

/*
-2  0
-3
0
-2

-2  0   -3
-2  -2  -3
*/

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */