class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output(n,1); // all ones, for multiplication. Assume int is large enough to hold the products
        int running_product = 1;
        for(int i=1; i < n; i++)
        {
            running_product *= nums[i-1];
            output[i] = running_product;
        }
        running_product = 1;
        for(int i = n-2; i >= 0; i--)
        {
            running_product *= nums[i+1];
            output[i] * = running_product;
        }
        return output;
    }
};