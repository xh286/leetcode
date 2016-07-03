class Solution {
public:
    double myPow(double x, int n) {
        // Given n, calculate in logn time, with O(1) space.
        // Example: n = 0b1111 (15). x^1 is known, if (n & 1<<0), then n &= ~(1<<0), if n still not zero, we calculate x^2, then x^4. If any bit is set, we multiply result by its value.
        if(x==0) return 0; // invalid value
        if(n<0)
        {
            n = ~n + 1; // absolute value. Example: 0xFFFF (-1) -> 1. 0xFFFC (-4) -> 4.
            x = 1/x;
        }
        double r = 1;
        double xd =  x; //x^1 = x, x^2=x^1*x^1, x^4=x^2*x^2. So, x1 for bit 0, x2 for bit 1, xi for bit (i-1).
        int i = 0;
        while(n)
        {
            if(n & (1<<i)) r *= xd;
            n &= ~(1<<i);
            xd = xd * xd;
            i++;
        }
        return r;
    }
};