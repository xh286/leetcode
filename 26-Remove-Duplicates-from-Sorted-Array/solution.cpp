class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // sorted array. Keep sorted. So do not use swap. Swap will cause missing duplicate detection later.
        int n = nums.size();
        int c = 0; // count number of val
        for(int i = 1; i < n; i++)
        {
            if(nums[i] == nums[i-1])
            {
                c++;
            }
            else
            {
                if(c > 0)
                {
                    nums[i-c] = nums[i];
                }
            }
        }
        return (n-c);
    }
};