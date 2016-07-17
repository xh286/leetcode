class HitCounter {
private:
    int hits;
    queue<pair<int,int>> history; // timestamp, count pair
    void process_fallout(int timestamp)
    {
        while(!history.empty())
        {
            if(timestamp - history.front().first >= 300)
            {
                hits -= history.front().second;
                history.pop();
            }
            else
                break;
        }
    }
public:
    /** Initialize your data structure here. */
    HitCounter():hits(0) {
        
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        process_fallout(timestamp);
        if(!history.empty() && history.back().first == timestamp)
            history.back().second++;
        else
            history.push({timestamp,1});
        hits++;
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        process_fallout(timestamp);
        return hits;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */