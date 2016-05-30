class Solution {
public:
    int numTrees(int n) {
        // For f(2n), it's 2*f(2n-1)*f(0)+2*f(2n-2)*f(1)+...+2*f(n-1)*f(n+1).
        // For f(2n+1), it's 2*f(2n)*f(0)+2*f(2n-1)*f(1)+...+2*f(n-1)*f(n+1)+f(n)*f(n).
        // Or, f(i), k = i half floored, 2*f(0)*f(i-1)+2*f(1)*f(i-1)+...+2*f(k-1)*f(i-k). If i odd, add f(k)*f(k).
        // Total complexity n^2. Define f(0)=1.
        vector<int> fn(n+1,0);
        fn[0] = 1;
        fn[1] = 1;
        for(int i = 2; i <= n; i++)
        {
            int k = i >> 1; // i half floored
            for(int c = 0; c < k; c++) // iterate summation with c
                fn[i] += 2 * fn[c]*fn[i-1-c];
            if(i & 1) // i is odd
                fn[i] += fn[k] * fn[k];
        }
        return fn[n];
    }
};