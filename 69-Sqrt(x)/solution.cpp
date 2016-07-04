class Solution {
public:
    int mySqrt(int x) {
        if(x<=0) return 0;
        // Think about how decimal square root works:
        // Example: 1'23. First find max a s.t. a*a<=1. Then find b such that (10a+b)^2=100a^2+20a*b+b^2<=123.
        // If 1'23'45, and b also found, then find c s.t. (100a+10b+c)^2=100*(10a+b)^2+20*(10a+b)*c+c^2<= 12345.
        // Define partial input pi (1, 123, 12345...), partial result pr (a, 10a+b,...), then in general we do:
        // Find maximum n s.t. 100*pr^2+20*pr*n+n^2<=pi, then pr = 10*pr+n. pi reads 2 more digits. If no more, return pr.
        // To simplify, subtract pr^2 from pi before continue reading more digits. So, pi = 23 after found a.
        // Only find 20*a*b+b^2 <= pi (23). Then subtract 20ab+b^2, so always compare 20*pr*n+n^2<=pi.
        // For binary representation, n can be only 0 or 1, and *2 instead of *10.
        // Count number of non-zero bits, find highest 2 bits value. This is initial pi. Initial pr = 0.
        // Then find whether 4*pr+1>pi. If yes, then new bit is 0. Otherwise new bit is 1. Subtract pi by 4*pr+1.
        // Then read 2 more bits. If got 2 more bits, pi = pi*4+new bits. If no more bits, return pr.
        // Draft below:
        int tx = x;
        int bit_count = 0;
        while(tx) // could use built-in clz.
        {
            bit_count++;
            tx >>= 1;
        }
        int bits_left = bit_count - 2 + (bit_count & 0x1);
        int pi = x >> bits_left; // partial input
        int pr = 1;
        pi -= 1;
        while(bits_left > 0)
        {
            bits_left -= 2;
            pi = (pi << 2) + ((x >> bits_left) & 0x3);
            int new_part = (pr << 2) + 1; // 4*pr+1
            if(new_part > pi)
            {
                // new bit is zero
                pr = pr << 1;
            }
            else
            {
                pr = (pr << 1) | 1;
                pi -= new_part;
            }
        }
        return pr;
    }
};