class Solution {
public:
    bool isPowerOfThree(int n) {
        // We know how to test power of two. How about three?
        // For power of two, we do: x & (x-1) == 0, unless it's 0 or 1. For large n (> 32/64 bits), the int itself should be large enough.
        // What to do with power of three? Need to extend the power of two logic somehow. No loop / recursion.
        // Example: 3 -> 0b11. 9 -> 0b1001, 27 -> 0x1B -> 0b11011. 81 -> 0x51 -> 0b01010001. Don't see any obvious patterns.
        // In fact, not so many power of 3s for 32-bit, even 64 bit integers. Same as number of recursion.
        if(n<1) return false;
        while(n>1)
        {
            if(n%3) return false;
            n /= 3;
        }
        assert(n==1);
        return true;
    }
};