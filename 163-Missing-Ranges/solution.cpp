class Solution {
private:
    void insertMissingRange(vector<string>& ret, int pre, int next)
    {
        ostringstream ss;
        int gap = next - pre;
        // assert(gap > 1);
        ss << pre + 1;
        if(gap > 2)
        {
            ss << "->" << next - 1;
        }
        ret.push_back(ss.str());
    }
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ret;
        int n = nums.size();
        int pre = lower-1;
        for(int i=0; i<n; i++)
        {
            int gap = nums[i]-pre; // expecting pre+1.
            if(gap > 1)
                insertMissingRange(ret, pre, nums[i]);
            pre = nums[i];
        }
        int gap = upper+1 - pre;
        if(gap > 1)
            insertMissingRange(ret, pre, upper+1);
        return ret;
    }
};