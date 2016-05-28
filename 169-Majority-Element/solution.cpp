class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::unordered_map<int, int> f; // frequency table
        int n = nums.size();
        int i = 0;
        for(i = 0; i < n; i++)
        {
            std::pair<int, int> new_pair = {nums[i], 1};
            if(f.find(nums[i]) == f.end()) // not found
                f.insert(new_pair);
            else
                f[nums[i]]++;
        }
        // look for majority element
        std::unordered_map<int,int>::const_iterator it;
        for(it = f.begin(); it != f.end(); ++it)
        {
            if(it->second > n/2)
                return it->first;
        }
    }
};