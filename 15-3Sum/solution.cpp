class Solution {
private:
    void insert_triplet(vector<vector<int>>& r, int a, int b, int c)
    {
        vector<int> triplet(3,0);
        triplet[0] = a;
        triplet[1] = b;
        triplet[2] = c;
        r.push_back(triplet);
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
            int a = nums[i];
            int target = -a;
            int j = i + 1;
            int k = n - 1;
            while(j<k)
            {
                int sum = nums[j] + nums[k];
                if(sum < target) j++;
                else if(sum > target) k--;
                else // hit
                {
                    int b = nums[j];
                    int c = nums[k];
                    insert_triplet(r, a, b, c);
                    while(j<k && nums[j] == b) j++;
                    while(j<k && nums[k] == c) k--;
                }
            }
            while(i<n-2 && nums[i+1] == a) i++; // this one not so straightforward. Example: [-1, -1, 0, 1, 2], [0, 0, 0, 1, 2].
        }
        return r;
    }
};