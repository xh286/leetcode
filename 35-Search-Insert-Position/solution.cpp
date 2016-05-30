class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // binary search, conservative version. Regular binary search is aggressive, and end condition is high < low.
        int high = nums.size() - 1;
        if(high < 0) return 0;
        int low = 0;
        // first deal with special cases: out of range
        if(target > nums[high])
            return high+1;
        if(target < nums[low])
            return 0;
        // Binary search, if hit return index; otherwise between low and high. return low+1.
        int mid;
        bool hit = false;
        while(high >= low)
        {
            mid = (high + low) / 2; // floored, because of this, can miss high.
            if(target > nums[mid])
                low = mid + 1;
            else if(target < nums[mid])
                high = mid - 1;
            else // hit
            {
                hit = true; break;
            }
        }
        if(hit)
            return mid;
        // no hit
        return low;
    }
};