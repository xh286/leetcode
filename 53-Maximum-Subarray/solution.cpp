class Solution {
private:
    vector<int> cons1(vector<int>& a) // consolidate all consecutive pos / negs.
    {
        vector<int> r;
        int n = a.size();
        int i = 0;
        while(a[i] <= 0) i++; // remove leading zeros and negatives
        int t = a[i++]; // now t is first non-zero entry
        for(; i<n; i++)
        {
            if(a[i] != 0) // ignore all zero entries
            {
                if( (a[i] > 0 && t > 0) || (a[i] < 0 && t < 0) ) // same sign as cumsum
                    t += a[i];
                else // sign changed
                {
                    r.push_back(t);
                    t = a[i];
                }
            }
        }
        return r;
    }
    vector<int> cons2(vector<int>& a) // consolidate a[k-1, k, k+1] if a[k]<0, and a[k]+a[k-1]>=0, a[k]+a[k+1]>=0.
    {// first number always positive, then alternating neg, pos.
        vector<int> r;
        int n = a.size();
        for(int i=2; i<n-1; i++) // jump to 3rd, 5th, 7th, then look back
        {
            if(a[i-1] < 0 && a[i-2] + a[i-1] >= 0 && a[i-1] + a[i] >=0) // consolidate
            {
                int sum = a[i-2]+a[i-1]+a[i];
                r.push_back();
            }
            else
            {
                r.push_back(a[i-2]);
                r.push_back(a[i-1]);
            }
        }
    }
    
public:
    int maxSubArray(vector<int>& nums) {
        // Naive solution is O(n^2), so we try to do better.
        // Cannot prove correctness, but here's a heuristic.
        // First consolidate all consecutive positives and consecutive negatives, remove all zeros.
        // Now the list is alternating negative / positive.
        // Look for negatives a[k] whose abs is no larger than the neighbors on both sides, i.e. a[k]+a[k-1]>=0 and a[k]+a[k+1]>=0. Do this until no more consolidation can be found.
        // Take max of the remaining list.
        vector<int> a(cons1(nums));
        int last_len = a.size();
        while(true)
        {
            a = cons2(a);
            if(a.size() == last_len)
                break;
            last_len = a.size();
        }
        
        return 0;
    }
};