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
            [](Interval a, Interval b){return (a.begin<b.begin);});
        vector<Interval> r;
        Interval new_interval = intervals[0];
        for(std::vector<Interval>::const_iterator it = intervals.begin(); it != itervals.end();)
        {
            auto it2 = it+1;
            if(it2 != intervals.end())
            {
                if(int_intersect(*it, *it2))
                {
                    new_interval.end = std::max(it->end, it2->end);
                }
                else
                {
                    r.push_back(new_interval);
                    new_interval = *it2;
                    it = it2;
                }
            }
            else
            {
                r.push_back(new_interval);
                it = it2;
            }
        }
        return r;
    }
};