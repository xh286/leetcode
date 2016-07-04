class Solution {
private:
    int findIndexNoGreater(vector<int>& nums, int low, int high, int target) // return index of last element <= target
    {
        if(target < nums[low]) return -1;
        if(target >= nums[high]) return high;
        while(high-low>1)
        {
            int mid = low + (high-low)/2;
            if(nums[mid] > target) high = mid;
            else if(nums[mid] < target) low = mid;
            else // mid matches, with duplicates, mid may not be last
            {
                while(mid<high && nums[mid+1] == nums[mid]) mid++;
                return mid;
            }
        }
        return low;
    }
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // Find exact match, or nearest match. Only need one if multiple results same sum.
        // Sort array at nlogn cost. Then require t1<=t2<=t3. Array has duplicates.
        // Given t1, iterate through t2 range, then look for desired t3. Use binary search. So n^2logn.
        // Brute force is O(n^3). Need to do better than that.
        // Diff = sum - target. Compare new abs(Diff) versus old.
        
        int n = nums.size();
        if(n<3) return 0;
        sort(nums.begin(), nums.end());
        int best_sum = nums[0]+nums[1]+nums[2];
        for(int i=0; i<n-2; i++) // t1
            for(int j=i+1; j<n-1; j++) // t2
            {
                int partial_sum = nums[i] + nums[j];
                int idx = findIndexNoGreater(nums,j+1,n-1,target - partial_sum);
                // prob next if idx valid
                if(idx>=j+1 && idx<n-1) 
                {
                    sum = partial_sum + nums[idx+1];
                    if(abs(sum-target) < abs(best_sum-target))
                        best_sum = sum;
                }
                // prob idx itself. j+1 if invalid.
                if(idx == -1) idx = j+1;
                sum = partial_sum + nums[idx];
                if(abs(sum-target) < abs(best_sum-target))
                    best_sum = sum;
            }
        return best_sum;
    }
};