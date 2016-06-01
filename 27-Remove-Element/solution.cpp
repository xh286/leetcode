class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int c = 0; // count number of val
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == val)
            {
                c++;
            }
            else
            {
                if(c > 0)
                {
                    nums[i-c] = nums[i];
                }
            }
        }
        return (n-c);
    }
    // My algorithm does not change the order of elements. So, suboptimal. Could be faster if using another pointer at end moving left. Just swap elements.
};