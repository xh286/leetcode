class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // binary search.
        int high = nums.size() - 1;
        int low = 0;
        // first deal with special cases: out of range
        if(target > nums[high])
            return high+1;
        if(target < nums[low])
            return 0;
        // Binary search, if hit return index; otherwise between low and high. return low+1.
        int mid;
        bool hit = false;
        while(high - low > 1)
        {
            mid = (high + low) / 2; // floored
            if(target > nums[mid])
                low = mid;
            else if(targe < nums[mid])
                high = mid;
            else // hit
            {
                hit = true; break;
            }
        }
        if(hit)
            return mid;
        return low+1;
    }
};