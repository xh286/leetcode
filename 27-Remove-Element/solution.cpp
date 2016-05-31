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
};