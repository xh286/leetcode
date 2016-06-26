class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> r;
        map<int,int> vm;
        for(int i=0; i<n; i++)//if duplicates, then use max of index as mapped value
            vm[nums[i]] = i;
        // Require that triplet[0]<=triplet[1]<=triplet[2].
        
        for(int i=0; i<n-2; i++)
        {
            if(nums[i] > 0) break;
            // Look in a[i+1...n-1] for a[j] and a[k], j !=k, s.t. a[j]+a[k] = -a[i].
            for(int j=i+1; j<n-1; j++)
            {
                int t_2sum = -nums[i]; // target for 2sum
                if(nums[j] > t_2sum/2) break;
                // find in a hash map the index of triplet[2].
                int target = t_2sum - nums[j];
                map<int,int>::iterator it = vm.find(target);
                if(it != vm.end() && it->second > j) // found match
                {
                    r.push_back();
                    r.back().push_back(nums[i]);
                    r.back().push_back(nums[j]);
                    r.back().push_back(it->first);
                }
            }
        }
        return r;
    }
};