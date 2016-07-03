class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // naive solution is O(n^3), by keeping cumsum, brute force solution is O(n^2).
        // By partitioning solutions into "ending at i", i=0...n-1 groups, the best solution for i can be derived from the best solution for i-1. And for i=0, it's trivial.
        // If best solution by i is maxsum[i], then for maxsum[i+1], it has to contain nums[i+1], if maxsum[i]>0, then just add, otherwise, just nums[i+1] itself.
        
        int maxsumi = nums[0]; // maxsum by i = 0.
        int max_sum = nums[0];
        int n = nums.size();
        for(int i=1; i<n; i++)
        {
            maxsumi = (maxsumi>0)?maxsumi:0;
            maxsumi += nums[i];
            if(maxsumi > max_sum) max_sum = maxsumi;  
        }
        return max_sum;
    }
};