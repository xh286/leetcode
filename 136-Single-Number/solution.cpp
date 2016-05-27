class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // A very special problem. Inputs are integers, and appear twice. x xor x == 0, x xor 0 == x.
        size_t n = nums.size();
        int output = 0;
        for(size_t i = 0; i < n; i++)
        {
            output ^= nums[i];
        }
        return output;
    }
};