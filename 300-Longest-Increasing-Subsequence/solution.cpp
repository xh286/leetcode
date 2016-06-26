class Solution {
private:
    int updateR(vector<int>& r, int x)
    {
        // locate position of x in ascending array r.
        // If hit, do nothing.
        // If r[i] < x < r[i+1], then r[i+1] = x.
        // Binary search.
        int n = r.size();
        int low = 0, high = n-1;
        while(low<=high) // check later
        {
            int mid = low + (high-low)/2; // floor(high+low). need to avoid overflow
            if(r[mid] > x)
                high = mid - 1;
            else if(r[mid] < x)
                low = mid + 1;
            else // hit
                return mid;
        }
        // x is in between r[low-1] and r[low], update r[low]
        if(low <= n-1)
            r[low] = x;
        else
            r.push_back(x);
        return low;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> r;
        if(n>0)
            r.push_back(nums[0]);
        for(int i=1; i<n; i++)
        {
            updateR(r,nums[i]);
        }
        return r.size();
    }
};