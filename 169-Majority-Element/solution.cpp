class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::unordered_map<int, int> f; // frequency table
        int n = nums.size();
        int i = 0;
        std::unordered_map<int,int>::iterator it;
        for(i = 0; i < n; i++)
        {
            it = f.find(nums[i]);
            if(it == f.end()) // not found
                f.insert({nums[i],1});
            else
                it->second++;
        }
        // look for majority element
        
        for(it = f.begin(); it != f.end(); ++it)
        {
            if(it->second > n/2)
                return it->first;
        }
        return 0;
    }
};