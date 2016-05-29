class Solution {
public:
    int integerBreak(int n) {
        // Try from small numbers, and notice if any factor >=5, then can be broken into smaller factors and get larger result.
        // Proof: if n even, then break into two equal factors, n^2/4>n when n>4. If n odd, then (n+1)*(n-1)/4>n.
        if(n == 2) return 1;
        if(n == 3) return 2;
        if(n == 4), return 4;
        int product = 1;
        while(n>=5)
        {
            product *= 3;
            n -= 3;
        }
        // n>=2 and <5, or n = 2, 3, 4.
        product *= n;
        return product;
    }
};