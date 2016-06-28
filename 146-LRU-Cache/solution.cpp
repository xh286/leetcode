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
    struct KVpair{
        int key;
        int value;
        KVpair(int k = 0, int v = 0):
            key(k), value(v){}
    };
    list<KVpair> LRUlist;
    typedef list<KVpair>::iterator LI; // pointer to nodes in list
    unordered_map<int,LI> key2addr;
    unsigned size;
    unsigned cap;
    
    void insertNodeAfterTail(int key, int value)
    {
        LRUlist.push_front({key,value});
        key2addr[key] = LRUlist.begin();
        size++;
    }
    void replaceLRU(int key, int value)
    {
        old_key = LRUlist.back().key;
        key2addr.erase(old_key);
        LRUlist.pop_back();
        LRUlist.push_front({key,value});
        key2addr[key] = LRUlist.begin();
    }
    void refreshEntry(LI it, int value)
    {
        int key = it->key;
        int value = value;
        LRUlist.erase(it);
        LRUlist.push_front({key, value});
        key2addr[key] = LRUlist.begin();
    }
public:
    LRUCache(int capacity) : head(NULL), tail(NULL), size(0), cap(capacity) {
        
    }
    
    int get(int key) {
        unordered_map<int,LI>::const_iterator it = key2addr.find(key);
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
        unordered_map<int,LI>::const_iterator it = key2addr.find(key);
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