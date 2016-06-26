class Solution {
    
private:
    int my_partition(vector<int>& a, int low, int high, int pivot) // choose pivot, partition and return pivot position
    {
        // assert(a.size() > high && high >= low);

        int pivot_value = a[pivot];
        a[pivot] = a[low]; // a[low] is now free space
        while(low < high)
        {
            while(low < high && a[high] >= pivot_value) high--;
            a[low] = a[high]; // now a[high] is free space
            while(low < high && a[low] <= pivot_value) low++;
            a[high] = a[low]; // now a[low] is free space
        }
        // assert(low == high); Actually the loop is pretty clean! Better than binary search!
        a[low] = pivot_value;
        return low;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Quickselect. Non-trivial.
        // Ending condition? Something equals zero
        int n = nums.size();
        int low = 0, high = n-1;
        std::default_random_engine generator;
        while(low<=high)
        {
            std::uniform_int_distribution<int> distribution(0, high-low);
            int pivot = my_partition(nums, low, high, low + distribution(generator));
            // [low...pivot-1] <= pivot, [pivot+1...high] >= pivot.
            int rl_include_pivot = high - pivot + 1; // length to the right, including pivot
            int ll_exclude_pivot = pivot - low;
            if(rl_include_pivot > k)
            {
                low = pivot + 1;
            }
            else if (rl_include_pivot < k)
            {
                k -= rl_include_pivot;
                high = pivot - 1;
            }
            else
            {
                return nums[pivot];
            }
        }
        return 0;
    }
};