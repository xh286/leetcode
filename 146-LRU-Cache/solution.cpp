class LRUCache{
    // cache is (key, value) store, usually using hash map.
    // Simple case is address mapped, cyclic.
    // LRU policy: just update timestamp (use a counter here) whenever accessed, then invalidate oldest entry.
    // Time complexity of naive implementation is O(n). To improve:
    // Keep a (key, counter) hash map. Keep a (counter, key) map.
    // New access: update (key, counter) hash map, locate iterator in (counter, key) map with old counter, then update counter value. All these can be done in O(logn) time. 
private:
    unsigned cap;
    unsigned size;
    unsigned counter;
    unordered_map<int,int> k2v;
    unordered_map<int,unsigned> k2t;
    map<unsigned,int> t2k;
    void update_ts(int key, unsigned ts)
    {
        t2k.erase(k2t[key]);
        t2k[ts] = key;
        k2t[key] = ts;
    }
    void eraseLRU()
    {
        map<unsigned,int>::iterator it = t2k.begin(); // how to handle counter wrap-around???
        t2k.erase(it);
        k2t.erase(it->second);
        k2v.erase(it->second);
        size--;
    }
    void insertNewpair(int key, int value, unsigned ts) // not exception safe
    {
        k2v[key] = value;
        k2t[key] = ts;
        t2k.insert({ts,key});
        size++;
    }
    void updatePair(int key, int value, unsigned ts)
    {
        k2v[key] = value;
        update_ts(key,ts);
        k2t[key] = ts;
    }
public:
    LRUCache(int capacity) : 
        cap(capacity), counter(0), size(0)
        {
    }
    
    int get(int key) { // not thread safe.
        unordered_map<int,int>::const_iterator it = k2v.find(key);
        if(it != k2v.end())
        {
            update_ts(key, counter);
            counter++;
            return it->second;
        }
        else // in real caches, this should trigger set().
            return -1;
    }
    
    void set(int key, int value) {// could modify value for a key!!
        unordered_map<int,int>::const_iterator it = k2v.find(key);
        if(it != k2v.end())
        {
            updatePair(key, value, counter);
            counter++;
        }
        else
        {
            if(size == cap)
            {
                eraseLRU(); // this will reduce size by 1.
            }
            
            insertNewpair(key, value, counter); // this will increase size by 1.
            counter++;
        }
        assert(k2v.size()==size);
        assert(k2t.size()==size);
        assert(t2k.size()==size);
    }
};