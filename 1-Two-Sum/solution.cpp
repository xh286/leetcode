class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Naive solution is O(n^2). If sort, then binary search, then O(nlogn).
        // Linear time possible with hash map.
        vector<int> r;
        unordered_map<int,int> m; // stores previous entries
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            unordered_map<int,int>::iterator it = m.find(target - nums[i]); // check if nums[i] matches any past number (sum == target).
            if(it != m.end()) // found solution
            {
                r.push_back(it->second); // "second" stores index of first number.
                r.push_back(i);
                return r;
            }
            else // no match
            {
                m.insert({nums[i],i}); // could be update if there are duplicate values in the vector
            }
        }
        return r; // 
    }
};