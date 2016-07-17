class Solution {
private:
    void insertRange(vector<string>& ret, int start, int end)
    {
        ostringstream ss;
        // assert(end>=start);
        ss << start;
        if(end>start)
            ss << "->" << end;
        ret.push_back(ss.str());
    }
public:
    vector<string> summaryRanges(vector<int>& nums) {
        // Keep start & end values. If next is end+1, then update end.
        // If not, then insert start & end pair. If start == end, only insert one.
        // After loop complete, process last pair.
        int n = nums.size();
        vector<string> ret;
        if(n==0) return ret;
        int start, end;
        start = end = nums[0];
        for(int i=1; i<n; i++)
        {
            if(nums[i] == end+1)
                end++;
            else
            {
                insertRange(ret, start, end);
                start = end = nums[i];
            }
        }
        insertRange(ret, start, end);
        return ret;
    }
};