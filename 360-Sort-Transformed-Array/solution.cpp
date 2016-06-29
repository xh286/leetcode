class Solution {

public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        // f(x) is a parabolic curve, where x is the sampling points. If a>0, then we are looking for where the sequence turns up, i.e. first i where f(i)<f(i+1). Reverse merge f(0...i) and f(i+1...n-1).
        // For simplicity, reverse f(0...i), then merge two sorted sequences.
        // If a<0, then find first i where f(i)>f(i+1), then reverse f(i+1...n-1) and merge.
        // If a==0, then reverse if b<0.
        int n = nums.size();
        vector<int> f(n);
        vector<int> r(n);
        for(int i=0; i<n; i++)
            f[i] = (a * nums[i] + b) * nums[i] + c;
        int low = 0, high = n-1;
        // if a==0, treat sign as -1.
        int j = (a>0)?n-1:0;
        int sign = (a>0)?1:-1;
        while(low<=high)
        {
            
            if(sign*f[low] <= sign*f[high])
            {
                r[j] = f[high--];
            }
            else
            {
                r[j] = f[low++];
            }
            j -= sign; // if a>0, then reverse.
        }
        return r;
    }
};