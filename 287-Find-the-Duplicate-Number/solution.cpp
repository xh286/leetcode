class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Emuerate simple cases, we find binary search is viable.
        // Divide n range into left, x, right, 3 parts, and count occurence of each set.
        // If x multiple, return x, otherwise, one of left and right satisfy occurence > set size.
        int n = nums.size() - 1;
        // handle invalid cases...
        if(n==-1) return 0;
        if(n==0) return nums[0];
        int low = 1;
        int high = n;
        int total_set_count = n + 1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int left_set_size = mid-low;
            int right_set_size = high-low;
            //int mid_set_size = 1;
            int left_set_count = 0;
            int mid_set_count = 0;
            int right_set_count = 0;
            for(int i=0; i<=n; i++)
            {
                if(nums[i]>=low && nums[i]<mid)
                    left_set_count++;
                else if(nums[i] == mid)
                    mid_set_count++;
                //else if(nums[i]>mid && nums[i]<=high)
                //    right_set_count++;
            }
            
            if(mid_set_count > 1) return mid;
            right_set_count = total_set_count - left_set_count - mid_set_count;
            if(left_set_count>left_set_size)
            {
                high = mid - 1;
                total_set_count = left_set_size;
            else// if(right_set_count>right_set_size)
            {
                low = mid + 1;
                total_set_count = right_set_size;
        }
        return 0;
    }
};