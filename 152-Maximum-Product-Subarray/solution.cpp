class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // Partition solution space into subarrays ending at i.
        // Track max and min ending at i, due to negative entries.
        int n = nums.size();
        vector<int> max_prod(n,0);
        vector<int> min_prod(n,0);
        if(n==0) return 0;
        max_prod[0] = nums[0];
        min_prod[0] = nums[0];
        // assuming no overflow when multiply... returning int.
        int ret = nums[0];
        for(int i=1; i<n; i++)
        {
            int prod1 = max_prod[i-1]*nums[i];
            int prod2 = min_prod[i-1]*nums[i];
            max_prod[i] = max(nums[i],max(prod1,prod2));
            min_prod[i] = min(nums[i],min(prod1,prod2));
            if(max_prod[i] > ret) ret = max_prod[i];
        }
        return ret;
    }
};