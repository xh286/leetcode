class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // Within a sliding window k, check for duplicates.
        // Naive solution is O(n*k) with O(1) space.
        // Fast solution is O(n) with a map, O(n) space.
        unordered_map<int,int> val_idx;
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            unordered_map<int,int>::iterator it = val_idx.find(nums[i]);
            if(it != val_idx.end()) // found duplicate value
            {
                if(i - it->second <= k) // return true
                    return true;
                else // update mapped value with i
                    it->second = i;
            }
            else // new key, insert
                val_idx.insert({nums[i], i});
        }
        return false;
    }
};