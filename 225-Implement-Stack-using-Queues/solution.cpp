class Stack {
private:
    vector<queue<int>> queues; // ping-pong
    int out_idx; // queues[out_idx] for pop, queues[out_idx^1] for other queue that's always empty except when operating.
    // When push, push new entry into other queue, and append entries in other queue. So output queue always has entries in reversed order.
public:
    // Push element x onto stack.
    void push(int x) {
        int n = queues[out_idx].size();
        int new_out_idx = out_idx^1;
        queues[new_out_idx].push(x);
        for(int i=0; i<n; i++)
        {
            queues[new_out_idx].push(queues[out_idx].front());
            queues[out_idx].pop();
        }
        out_idx = new_out_idx;
    }

    // Removes the element on top of the stack.
    void pop() {
        queues[out_idx].pop();
    }

    // Get the top element.
    int top() {
        return queues[out_idx].front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return queues[out_idx].empty();
    }
    Stack(): out_idx(0), queues(vector<queue<int>>(2,queue<int>())) {} // constructor
};