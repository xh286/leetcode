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
    int locate(vector<Interval>& intervals, int val) // search for val in intervals. Return index of interval if val is enclosed by one. Return index of next interval if not found.
    {
        int low = 0;
        int high = intervals.size()-1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(val > intervals[mid].end) low = mid + 1;
            else if(val < intervals[mid].start) high = mid - 1;
            else return mid;
        }
        return low;
    }
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int n = intervals.size();
        int start = newInterval.start;
        int end = newInterval.end;
        int left = locate(intervals, start);
        int right = locate(intervals, end);
        bool left_hit = false;
        if(left < n)
            left_hit = (start >= intervals[left].start) && (start <= intervals[left].end);
        if(right < n)
            right_hit = (end >= intervals[right].start) && (end <= intervals[right].end);
        if(left_hit)
            start = min(start, intervals[left].start);
        if(right_hit)
            end = max(end, intervals[right].end);
        vector<Interval> ret;
        int i;
        for(i=0; i<n; i++)
            if(intervals[i].end < start)
                ret.push_back(intervals[i]);
            else
                break;
        for(; i<n; i++)
            if(intervals[i].end > end)
                break;
        ret.push_back(Interval(start,end));
        for(; i<n; i++)
            ret.push_back(intervals[i]);
            
        return ret;
        
    }
};