class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // 3 ways: 1. copy to another array in with shifted index. O(n) space, O(n) time
        // 2. Create a length k vector to store last k entries of input, move entries of input to the right, then copy back first K.
        // 3. Run k iterations, in each iteration, starting from index i (0...k-1), increment index by k each time, until wrapped around. Question is how to hanlde the wraparound efficiently.
        // Example: n = 100, k = 2. Copy a[0] to a[2], a[2] to a[4],.., a[98] to a[0].
        int n = nums.size();
        // check corner conditions here!
        if(n<=1) return;
        // k could be very large!
        k = k%n;
        // Depending on whether n%k==0, two different ways
        if(n%k == 0) // k independent rings
        {
            for(int i=0; i<k; i++) // starting index for each iteration
            {
                int val = nums[n-k+i]; // last one in the chain, wrapped around. 
                for(int j=i; j < n; j+=k) // copy from a[j-k] to a[j]
                {
                    int temp = nums[j];
                    nums[j] = val;
                    val = temp;
                }
            }
        }
        else // single ring
        {
            int val = nums[0];
            int j = k;
            for(int i=0; i<n; i++)
            {
                int temp = nums[(j+k)%n];
                nums[(j+k)%n] = val;
                val = temp;
                j += k;
            }
        }
        return;
    }
};