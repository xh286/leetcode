class Queue {
    // The problem is like a person processing mails in the order of reception.
    // He has a mailbox, new mail always gets stacked at the top.
    // He has a desk with a pile of mail. New mail always gets processed from the top.
    // Assume the mailbox is unlimited in size.
    // If his desk is empty, and someone asks him to process a mail, he goes to the mailbox and fetches all the mail home, reverse their order onto his desk, and start processing. Meanwhile, his mailbox continues to receive mail.
    stack<int> mailbox; // mail comes in, top is end of queue.
    stack<int> desk; // mail gets processed, top is front of queue.
    private fetch_mail()
    {
        int n = mailbox.size();
            for(int i=0; i < n; i++)
        {
            desk.push(mailbox.top());
            mailbox.pop();
        }
    }
public:
    // Push element x to the back of queue.
    void push(int x) {
        mailbox.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if(desk.empty())
            fetch_mail();
        // assert(!desk.empty()) // If popped when both mailbox and desk empty, generate error
        if(!desk.empty())
            desk.pop();
    }

    // Get the front element.
    int peek(void) {
        if(desk.empty())
            fetch_mail();
        // assert(!desk.empty())
        return desk.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return(desk.empty() && mailbox.empty());
    }
};