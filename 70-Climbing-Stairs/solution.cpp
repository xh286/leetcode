class Solution {
public:
    int climbStairs(int n) {
        // Think from the last step: it could be taken as part of 2 steps, or taken individually. So we have f(n) = f(n-2) +f(n-1) where f(1) = 1, f(2) = 2. This is a Fibonacci series.
        // Now we just implement linear complexity algorithm, then logarithm complexity algorithm with matrix trick.
        // Implement matrix trick directly. Uses O(logn) time and space.
        // Find out highest bit position in n
        if(n<=0) return 0;
        if(n==1) return 1;
        // now n > 1. Find out highest bit pattern in (n-1).
        unsigned bit_pattern = (unsigned) (n-1);
        // (f(n), f(n-1)) = A^(n-1) * (1, 1) where A is matrix [1, 1; 1, 0].
        // To calculate B = A^(n-1), we first calculate A, A^2, A^4, ... and store in a vector of matrices. Then the matrices are multiplied together according to bit patterns in "bit_pattern": if a bit is set, then the corresponding matrix is multiplied.
        
        int w = 0;
        while(bit_pattern != 0)
        {
            w++;
            bit_pattern >>= 1;
        }
        bit_pattern = (unsigned) (n-1); // restore value
        vector<vector<int>> a(w, vector<int>(4,0)); // a[0] corresponds to bit 0 of bit_pattern. If 32-bit n, then w up to 32, a[31] for highest bit in bit_pattern. Now a[w-1] for highest bit in bit_pattern, stores A^(2^31);
        // Initialize
        a[0] = {1, 1, 1, 0}; // matrix [1, 1; 1, 0]
        // calculate all A^(2^m) where m = 1, ... w-1.
        for(int i=1; i<w; i++)
        {
            a[i][0] = a[i-1][0]*a[i-1][0] + a[i-1][1]*a[i-1][2];
            a[i][1] = a[i-1][0]*a[i-1][1] + a[i-1][1]*a[i-1][3];
            a[i][2] = a[i-1][2]*a[i-1][0] + a[i-1][2]*a[i-1][3];
            a[i][3] = a[i-1][2]*a[i-1][1] + a[i-1][3]*a[i-1][3];
        }
        // calculate b according to bit_pattern
        vector<int> b = {1, 0, 0, 1}; // start with diagonal unit matrix I.
        int d = 0;
        while(bit_pattern != 0)
        {
            if(bit_pattern & 1) // lowest bit is set, then multiply
            {
                vector<int> c = b; // c is temporary matrix holding prior value of b
                // b = c * a[d].
                b[i][0] = c[0]*a[d][0] + c[1]*a[d][2];
                b[i][1] = c[0]*a[d][1] + c[1]*a[d][3];
                b[i][2] = c[2]*a[d][0] + c[2]*a[d][3];
                b[i][3] = c[2]*a[d][1] + c[3]*a[d][3];
            }
            d++;
            bit_pattern >>= 1;
        }
        assert(d == w);
        // Get (f(n), f(n-1)) = b * (1, 1), or f(n) = b[0] + b[1].
        return (b[0] + b[1]);
    }
};