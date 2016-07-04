class Solution {
private:
    void unique_insert(vector<vector<int>>& r, int a, int b, int c)
    {
        int n = r.size();
        for(int i = 0; i < n; i++)
        {
            if(r[i][0] == a && r[i][1] == b && r[i][2] == c)
                return;
        }
        r.push_back(vector<int>());
        r.back().push_back(a);
        r.back().push_back(b);
        r.back().push_back(c);
    }
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
                    unique_insert(r, nums[i], nums[j], nums[k]);
                    j++; k--; // move on. If j++, k doesn't change, and hit again, then must be duplicate. So k--;
                }
            }
        }
        return r;
    }
};