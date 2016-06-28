class LRUCache{
    // Improved version. Using a linked list of (key, value, n) nodes pointed to by a hash map.
    // Number n is transaction number, starting from 0, and increments at every successful get & set.
    // When approaching overflow, needs reset.
    // Linked list is managed with a tail pointer, list is circular, tail->next is head.
    // Each new node corresponds to one cache entry, and address is stored in (key, addr) hash map.
    // Linked list is sorted by n, so head is most recently accessed entry, tail is least recently accessed entry.
    // When get, look for addr in hash map, then "access it". This means update n and move the node to tail->next.
    // When set, if new node, create new one, register in hash map, and "access it".
    // When set and need eviction, replace tail node content, update hash map key, and then "access" tail node.
private:
    struct ListNode{
        int key;
        int value;
        unsigned n;
        ListNode* pre;
        ListNode* next;
        ListNode(int k = 0, int v = 0, unsigned t = 0, ListNode* p1 = NULL, ListNode* p2 = NULL):
            key(k), value(v), n(t), pre(p1), next(p2){}
    };
    unordered_map<int,ListNode*> key2addr;
    ListNode* head;
    ListNode* tail;
    unsigned t;
    unsigned size;
    unsigned cap;
    
    void insertNodeAfterTail(int key, int value)
    {
        ListNode* p = new ListNode(key, value, t, tail, head);
        if(head == NULL) // empty list, first node
        {
            tail = head = p;
            tail->next = tail->pre = head;
        }
        else
        {
            head->pre = p;
            head = p;
            tail->next = head;
        }
        key2addr[key] = p;
        t++;
        size++;
    }
    void replaceLRU(int key, int value)
    {
        key2addr.erase(tail->key); // erase old key -> tail mapping
        tail->key = key;
        tail->value = value;
        tail->n = t;
        key2addr[key] = tail; // build new key -> tail mapping
        // old tail becomes new head. move both head & tail backwards. works even if only 1 node.
        head = tail;
        tail = tail->pre;
        t++;
    }
    void refreshEntry(ListNode* p, int value)
    {
        p->n = t;
        p->value = value;
        if(p == head) // p points to head, no processing needed.
            return;
        if(p == tail) // p points to tail, includes capacity=1 case.
        {
            head = tail;
            tail = tail->pre;
            return;
        }
        // p must not be head or tail. Move node pointed by p to head.
        p->pre->next = p->next;
        p->next->pre = p->pre;
        p->pre = tail;
        p->next = head;
        head->pre = p;
        tail->next = p;
        head = p;
        t++;
    }
public:
    LRUCache(int capacity) : head(NULL), tail(NULL), t(0), size(0), cap(capacity) {
        
    }
    
    int get(int key) {
        unordered_map<int,ListNode*>::const_iterator it = key2addr.find(key);
        int val = -1;
        if(it != key2addr.end())
        {
            val = it->second->value;
            refreshEntry(it->second, val);
        }
        return val;
    }
    
    void set(int key, int value) {
        // Cache value for given key could be updated!
        unordered_map<int,ListNode*>::const_iterator it = key2addr.find(key);
        if(it != key2addr.end())
        {
            refreshEntry(it->second, value);
        }
        else
        {
            if(size == cap)
                replaceLRU(key, value);
            else
                insertNodeAfterTail(key, value);
        }
    }
    // Note: actually t is not needed, as we manually maintain it.
    // Could implement in C++ way, using the list container. That would be better for interview.
    // Would use more hash set erase, insert, but hash set erase, insert are fast anyway.
};