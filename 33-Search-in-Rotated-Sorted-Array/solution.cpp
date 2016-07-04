class Solution {
public:
    int search(vector<int>& nums, int target) {
        // no dup makes it much easier
        // First locate original begin & end. That's where it starts to drop. Then determine which part to search. Then binary search again.
        int n = nums.size();
        if(n==0) return -1;
        int low = 0;
        int high = n-1;
        int mid;
        int begin;
        // rotated or not?
        if(nums[low] <= nums[high]) // contains n==1 case
            begin = 0;
        else // begin != 0
        {// search for begin
            while(high-low>1) // we always have nums[low] > nums[high], and begin is in between.
            {
                mid = low +(high-low)/2; // if high-low < 2, mid could overlap with low & high.
                if(nums[mid]>nums[low]) low = mid; // mid cannot be begin
                else if(nums[mid]<nums[high]) high = mid; // 
            }
            begin = high;
            assert(nums[begin-1]>nums[begin]);
            // Got begin
            if(target>nums[n-1])
            { 
                low = 0; 
                high = begin - 1; 

            }
            else if(target<nums[0])
            {
                low = begin;
                high = n-1;
            }
        }
        // regular binary search
        while(low<=high)
        {
            mid = low +(high-low)/2;
            if(target>nums[mid]) 
                low = mid + 1;
            else if(target<nums[mid]) 
                high = mid - 1;
            else
                return mid;
        }
        return -1;
    }
};