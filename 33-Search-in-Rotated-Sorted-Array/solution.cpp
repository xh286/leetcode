class Solution {
public:
    int search(vector<int>& nums, int target) {
        // no dup makes it much easier
        // First locate original begin & end. That's where it starts to drop. Then determine which part to search. Then binary search again.
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int mid;
        // search for begin
        while(low<high) // we always have nums[high] < nums[low], and begin is in between.
        {
            mid = low +(high-low)/2;
            if(nums[mid]>nums[low]) low = mid + 1; // mid cannot be begin
            else if(nums[mid]<nums[high]) high = mid; // 
        }
        int begin = low;
        if(begin>0) assert(nums[begin-1]>nums[begin]);
        if(begin==0)
        {
            low = 0;
            high = n-1;
        }
        else
        {
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
            if(target>nums[mid]) low = mid + 1;
            else if(target<nums[mid]) high = mid - 1;
            else
                return mid;
        }
        return -1;
    }
};