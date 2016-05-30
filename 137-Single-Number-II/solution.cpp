class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // Extension to the twice except for one problem. The essence of xor is add without carry. No interference to other bits.
        // Count occurrence of 1 in each bit, it should be multiple of 3 if not for the single number. Take modulo 3 of the counts.
        // If the single number appears only once, then the counts should be all 0 or 1 for each bit.
        // If twice, then all 0 or 2 for each bit. So, if for certain bit, the count > 0, then set 1.
        // First get integer size.
        int w = 32;
        vector<int> counts(w,0); // could be reduced to 2 bits * w instead of w ints. Constant space anyway.
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            int num = nums[i];
            for(int j=0; j<w; j++)
            {
                if(num & (1<<j))
                    counts[j] ++; // count total number of nums with bit j set
            }
        }
        int result = 0;
        for(int j=0; j<w; j++)
        {
            if( (counts[j]%3) != 0 )
                result |= (1<<j); // set bit j
        }
        return result;
    }
};