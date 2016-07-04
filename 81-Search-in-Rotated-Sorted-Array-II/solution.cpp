class Solution {
private:
    int findbegin(vector<int>& nums) // size >=2, return index of begin
    {
        // If nums[end]>nums[begin], then not rotated, begin=0.
        // If nums[end]=nums[begin], don't know.
        // If nums[end]<nums[begin], rotated, begin>0.
        // Extreme case is entire array is flat. Ignore it first.
        // First write code for no duplicates, then modify for duplicates.
        int low = 0; 
        int high = nums.size()-1;
        if(high<=0) return 0;
        if(nums[low]<nums[high]) return 0;
        // nums[low]>=nums[high]. Locate the pair of numbers i, i+1: nums[i]>nums[i+1]. Not exist if array is flat.
        while(high-low>1) // guarantee mid != low, otherwise comparing to self
        {
            int mid = low + (high-low)/2;
            if(nums[mid]>nums[high]) low = mid;
            else if(nums[mid]<nums[low]) high = mid;
            else if(nums[mid] == nums[low])
            {// must have nums[mid] == nums[high] as well.
                assert(nums[mid] == nums[high]);
                // Linear search for nums[i] low...high that's not same as nums[low].
                // If first different entry is smaller, then it's begin. If larger, then set it to low
                for(int i=low; i<=high; i++)
                {
                    if(nums[i] < nums[low])
                        return i;
                    if(nums[i] > nums[low])
                    {
                        low = i; break;
                    }
                }
            }
        }
        return high;
    }
    int binary_search(vector<int>& nums, int low, int high, int target)
    {
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(nums[mid] < target) low = mid + 1;
            else if(nums[mid] > target) high = mid - 1;
            else // equal
                return mid;
        }
        return -1;
    }
    
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==0) return false;
        if(n==1) return (target==nums[0])?true:false;
        int begin = findbegin(nums);
        int low = 0;
        int high = n-1;
        if(begin != 0)
        {
            if(target<=nums[high])
                low = begin;
            else // target > nums[high]
                high = begin-1;
        }
        return (binary_search(nums, low, high, target) != -1);
    }
};