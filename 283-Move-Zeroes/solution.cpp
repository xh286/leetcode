class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        size_t n = nums.size();
        size_t i = 0; // index
        size_t c = 0; // count of zeros
        while(i < n)
        {
            if(nums[i] == 0) //consecutive zeros
            {
                c++;
            }
            else // (nums[i] != 0) // consecutive non-zeros
            {
                nums[i-c] = nums[i];
            }
            i++;
        }
        // Replace last c entries with zeros
        i = n - c;
        while(i < n)
        {
            nums[i] = 0;
            i++;
        }
    }
};