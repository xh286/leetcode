class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // General solution is to insert into hash set, then check one by one. Uses O(n) space.
        // Do better: Same as single number problem. n valid range: >= 0.
        int n = nums.size();
        int i = 0, result = 0;
        while(i < n)
        {
            result ^= nums[i];
            i++;
            result ^= i;
        }
        return result;
    }
};