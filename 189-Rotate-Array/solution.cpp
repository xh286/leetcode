class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // 3 ways: 1. copy to another array in with shifted index. O(n) space, O(n) time
        // 2. Create a length k vector to store last k entries of input, move entries of input to the right, then copy back first K.
        // 3. Run k iterations, in each iteration, starting from index i (0...k-1), increment index by k each time, until wrapped around. Question is how to hanlde the wraparound efficiently.
        // Example: n = 100, k = 2. Copy a[0] to a[2], a[2] to a[4],.., a[98] to a[0].
        int n = nums.size();
        if(n<=1) return;
        k = k%n;
        if(k==0) return;
        // Count total n writes. Each cycle stops when detect src == start. Then start++.
        int c = 0;
        int start = 0;
        int src = start;
        int val_to_write = nums[start];
        while(c<n)
        {
            dest = (src+k)%n;
            int temp = nums[dest];
            nums[dest] = val_to_write;
            val_to_write = temp;
            c++;
            src = dest;
            if(src == start)
            {
                // A cycle has completed
                start++; // won't wrap around
                src = start;
                val_to_write = nums[start];
            }
        }
        return;
    }
};