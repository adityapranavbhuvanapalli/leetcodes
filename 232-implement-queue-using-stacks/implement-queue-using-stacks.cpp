class MyQueue {
public:
    stack<int> s1, s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        int top;
        if(s2.size()) {
            top = s2.top();
            s2.pop();
            return top;
        }

        while(s1.size()) {
            s2.push(s1.top());
            s1.pop();
        }

        top = s2.top();
        s2.pop();
        return top;
    }
    
    int peek() {
        if(s2.size()) {
            return s2.top();
        }

        while(s1.size()) {
            s2.push(s1.top());
            s1.pop();
        }

        return s2.top();
    }
    
    bool empty() {
        return s1.size() + s2.size() == 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */