class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> r;
        int n = nums.size();
        if(n<3) return r;
        std::sort(nums.begin(), nums.end());
        // For sorted array, 2sum is linear complexity without hash map.
        // Require that t1<=t2<=t3.
        for(int i=0; i<n-2; i++)
        {
            int target = -nums[i];
            int j = i + 1;
            int k = n - 1;
            while(j<k)
            {
                int sum = nums[j] + nums[k];
                if(sum < target) j++;
                else if(sum > target) k--;
                else // hit
                {
                    r.push_back(vector<int>());
                    r.back().push_back(nums[i]);
                    r.back().push_back(nums[j]);
                    r.back().push_back(nums[k]);
                    while(j<k && nums[j+1] == nums[j]) j++;
                    while(j<k && nums[k-1] == nums[k]) k--;
                }
            }
        }
        return r;
    }
};