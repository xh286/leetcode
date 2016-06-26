/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
private:
    bool int_intersect(const Interval& a, const Interval& b) const
    {
        return ~((a.start > b.end) || (b.start > a.end));
    }
    
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        // Sort by start, then go through list once.
        // Optionally, after sort by start, for same start, keep only max end version.
        std::sort(intervals.begin(), intervals.end(),
            [](Interval a, Interval b){return (a.start<b.start);});
        vector<Interval> r;
        Interval new_interval;
        if(!intervals.empty())
            new_interval = intervals[0];
        for(std::vector<Interval>::const_iterator it = intervals.begin(); it != intervals.end();)
        {
            auto it2 = it+1;
            for(; it2 != intervals.end() && int_intersect(*it, *it2); it2++)
            {
                new_interval.end = std::max(it->end, it2->end);
            }
            r.push_back(new_interval);
            if(it2 != intervals.end())
            {
                new_interval = *it2;
                it = it2;
            }
        }
        return r;
    }
};