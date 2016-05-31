class Solution {
public:
    int rob(vector<int>& nums) {
        // Define value of rob(n) as f(n). f(0)= 0, f(1) = nums[0], f(n) = max(f(n-1), f(n-2)+nums[n-1]).
        // No need for vector storage, because only need last two values of f. Call them: f, f_1less, f_2less.
        int f_2less = 0;
        int f_1less = nums[0];
        int f;
        int n = nums.size(); 
        for(int i=2; i <= n; i++) // calculate f(i). f_1less stores f(i-1), f_2less stores f(i-2).
        {
            f = max(f_1less, f_2less+nums[i-1]);
            f_2less = f_1less; // initially calculate f(2) using f(1) and f(0). After this, store f(1) and f(2)
            f_1less = f;
        }
        return f;
    }
};