class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        // First calculate cumsum u[0...n-1] in O(n), then any range sum a[i...j] = u[j]-(u[i-1] or 0) can be got in O(1).
        // We want to see whether any (i,j) pair satisfies sum a[i...j] = k. If yes, update max_len to (j-i+1).
        // To do this, insert u into hash set, then check existence of k+u[i], if we get u[j], then k=u[j]-u[i], meaning sum(i+1...j)==k, so update max_len to j-i.
        // To make it more uniform, set u[0] = 0, and u[i] = cumsum(i+1). So u[n] is sum of all numbers.
        // We check k+u[i], i=0...n. Actually no need to check u[n], as it yields len 0.
        int max_len = 0;
        int n = nums.size();
        if(n==0) return 0;
        unordered_map<int,int> u2n;
        vector<int> u(n+1,0);
        
        for(int i=1; i<n+1; i++)
        {
            u[i] += u[i-1]+nums[i-1];
            u2n[u[i]] = i; // maps cum_sum to 1...n
        }
        for(int i=0; i<n; i++)
        {
            auto it = u2n.find(k+u[i]); // when i==0, u[0] = 0, so finding ranges starting from index 0.
            if(it != u2n.end())
                max_len = max(max_len, it->second - i);
        }
        return max_len;
    }
};