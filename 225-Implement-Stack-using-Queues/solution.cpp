class Stack {
    // Just one queue is good enough. 
private:
    queue<int> q;
public:
    // Push element x onto stack.
    void push(int x) {
        int n = q.size();
        q.push(x);
        while(n--) 
        {
            q.push(q.front());
            q.pop();
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        q.pop();
    }

    // Get the top element.
    int top() {
        return q.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }
};