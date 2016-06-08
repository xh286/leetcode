class Solution {
public:
    vector<int> grayCode(int n) {
        // To generate grayCode(n) from grayCode(n-1), we just insert 0 to all rows, then duplicate all rows, and replace first 0 with 1. Size of result is doubled every time.
        // Output is not 0/1 bits, but numbers. So, we don't have to insert zeros. After duplicate, just subtract.
        // First two entries are 0, 1. This is iteration 1. One bit.
        // For iteration 2, just duplicate all in reverse order, then add 2^1. Two bits.
        // For iteration 3, just duplicate all in reverse order, then add 2^2.
        // Do this until iteration n, duplicate all, then add 2^(n-1). In total we get 2^n numbers.
        vector<int> r;
        r.reserve(1 << n); // 2^n
        // Do n iterations
        r.push_back(0);
        for(int k=1; k<=n; k++) // iteration k
        {
            int s = r.size(); // do for all existing rows after previous iteration (k-1).
            for(int i=s-1; i>=0; i--)
                r.push_back( (1 << (k-1)) + r[i] ); // verify with k==2, okay
        }
        return r;
        // Need to check input n range! If n==0, return 0.
    }
};