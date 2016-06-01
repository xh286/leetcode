class Solution {
public:
    int trailingZeroes(int n) {
        // All factorials except 1! are even, actually many 2 factors coming from 2, 4, 6, 8, etc.
        // So the limiting factor is the number of factor 5s.
        // Each time a 5 multiple is found, the number of trailing zeros increments by 1.
        // For 25, it contributes two 5 factors, so adds another trailing zero. Same for 25 multiples.
        // For 125 (5^3), it contributes another additional trailing zero.
        // So the algorithm counts the number of 5 factors <= n, which is given by n/5. For each, add 1, so total add (n/5).
        // Then counts the number of 5^2 factors, given by n/(5^2). For each, add 1, so total add (n/5^2).
        // This ends at ith iteration when n < 5^i. Initially i starts at 1.
        
        // Assume invalid if n<0.
        if(n < 5) return 0;
        int r = 0; // result
        int p = 5; // power of five, the power being i. Initially, i = 1, and p = 5.
        while(n >= p)
        {
            r += n/p;
            p = p * 5;
        }
        return r;
        // Now verify the algorithm.
        // n= 6, p=5, n>p, so r+=1, p = 25. stop, r = 1.
        // n = 125, p=5, so r+= 125/5=25, p=25, r+= 125/25=5, p=125, r+= 1. Total 25+5+1. Correct.
    }
};