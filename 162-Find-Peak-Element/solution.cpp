class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // O(n) solution trivial. So try logn.
        // Binary search. First detect whether two ends satisfy, if not, then both upward sloping going in.
        // Then find mid, detect whether it's peak. If not, at least one side is upward sloping.
        // So, we get half part that satisfies. Such a part must include a peak element, because we already have one up and one down. As long as at least one up and one down, there will be a peak.
        int n = nums.size();
        if(n==0) return -1; // return index. -1 is invalid.
        if(n==1) return 0;
        // detect ends
        if(nums[0]>nums[1]) return 0;
        if(nums[n-2]<nums[n-1]) return (n-1);
        // Now n>=3. And nums[0]<nums[1] (going up), nums[n-2]>nums[n-1] (going down).
        // So nums contains at least one up (1), and one down (-1). Consider a mix of 1 & -1, and first is 1, last is -1. Pair (1,-1) must appear somewhere, that's the peak.
        int i = 0;
        int j = n-1;
        while(true) // should always return from within loop. When j-i==2 (length 3), must return mid element.
        {
            int k = i + (j-i)/2; // k must be between 1...n-2
            if(nums[k]>nums[k-1] && nums[k]>nums[k+1]) return k;
            if(nums[k]<nums[k-1]) // includes two cases, nums[k]>nums[k+1], or nums[k]<nums[k+1]. Prefer left.
                j = k;
            else // nums[k]>nums[k-1] && nums[k]<nums[k+1]
                i = k;
        }
        return -1;
    }
};