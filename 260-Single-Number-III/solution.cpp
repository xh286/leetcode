class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // The xor result is the different bits between the two numbers
        // use one bit to partition entire set into two subsets, then each subset xor result is a number.
        int n = nums.size();
        int bit_pattern = 0;
        vector<int> output(2,0);
        for(int i=0; i < n; i++)
        {
            bit_pattern ^= nums[i];
        }
        // find one set bit out of bit_pattern
        int pos = 0;
        while(0 == (bit_pattern & 0x1))
        {
            bit_pattern >>= 1;
            pos++;
            if(bit_pattern == 0)
                return output; // failure, return two zeros. Caller can find out.
        }
        // bit [pos] of bit_pattern was set

        for(int i=0; i < n; i++)
        {
            if(nums[i] & (1<<pos)) // if bit [pos] is set, put into same set as num1
            {
                output[0] ^= nums[i];
            }
            else
            {
                output[1] ^= nums[i];
            }
        }
        return output;
    }
};