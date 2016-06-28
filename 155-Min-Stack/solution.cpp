class MinStack {
private:
    stack<int> s;
    stack<int> m;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        s.push(x);
        if(m.empty() || x <= m.top())
            m.push(x);
    }
    
    void pop() {
        if(s.empty()) return;
        // assert(!m.empty());
        if(s.top() == m.top())
            m.pop();
        s.pop();
    }
    
    int top() {
        //assert(!s.empty());
        return s.top();
    }
    
    int getMin() {
        //assert(!m.empty());
        return m.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */