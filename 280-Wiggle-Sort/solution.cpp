class Solution {
    // simple answer is sort, then swap every pair other than first element.
    // Can we do it faster? For example O(n)?
    // Yes, just one-by-one.
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        for(int i=1; i<n; i++)
        {
            if(i & 0x1) //odd, should be no smaller than pre
            {
                if(nums[i] < nums[i-1])
                    swap(nums[i-1],nums[i]);
            }
            else // even, should be no larger than pre
            {
                if(nums[i] > nums[i-1])
                    swap(nums[i-1],nums[i]);
            }
        }
    }
};