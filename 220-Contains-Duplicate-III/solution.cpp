class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        // Sliding window problem. Keep a multiset of all values inside the window.
        // Look for all entries in [x[i]-t, x[i]+t] range, if any hit, then found.
        // We need a multiset, because otherwise erase will cause problem.
        // Optimize: actually, we only need to find first element satisfying >= x[i]-t then test if <= x[i]+t.
        // If it doesn't, then no need to check larger entries.
        // Potential overflow: use long long for tree entries. If x[i] already INT_MIN, t>=0, then stop at INT_MIN.
        int n= nums.size();
        if(n==0 || k<=0 || t<0) return false;
        if(k>n-1) k = n-1;
        multiset<int> window; // size k
        for(int i=0; i<k; i)
            window.insert(nums[i]);
        for(int i=k; i<n; i++)
        {
            long long val_to_test = static_cast<long long>(nums[i]) - t;
            if(val_to_test < INT_MIN) val_to_test = INT_MIN;
            auto it = window.lower_bound(static_cast<int>(val_to_test));
            if(it != window.end())
            {
                val_to_test = static_cast<long long>(nums[i]) + t;
                if(val_to_test > INT_MAX) val_to_test = INT_MAX;
                if(*it <= static_cast<int>(val_to_test))
                    return true;
            }
            window.erase(nums[i-k]);
            window.insert(nums[i]);
        }
        return false;
    }
};