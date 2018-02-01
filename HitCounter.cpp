class HitCounter {
public:
    // in seconds
    // 300 seconds = 5 mins
    /** Initialize your data structure here. */
    map<int, long> hits;
    map<int, long>::iterator itr;
    int total;
    HitCounter() {
        // timestamp -> hits
        hits[0] = 0;
        total = 0;
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        hits[timestamp] += 1;
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        total = 0;
        for(itr = hits.begin(); itr != hits.end(); ++itr) {
            if(timestamp - itr->first + 1 > 300) continue;
            total += itr->second;
        }
        return total;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */
