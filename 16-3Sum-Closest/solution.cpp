class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // On sorted array, 2sum is linear complexity. Two-pointer.
        int n = nums.size();
        if(n<3) return 0;
        sort(nums.begin(), nums.end());
        int best_sum = nums[0] + nums[1] + nums[2];
        for(int i=0; i<n-2; i++)
        {
            int target_2sum = target - nums[i];
            int j = i+1;
            int k = n-1;
            while(j<k)
            {
                sum2 = nums[i]+nums[j];
                sum = sum2 + 
                if(abs(target_2sum-sum2)<abs(best_sum-target)) best_sum = sum2 + nums[i];
                if(sum2 < target)   j++;
                else if(sum2 > target) k--;
                else // equal
                    return target;
            }
        }
        return best_sum;
    }
};