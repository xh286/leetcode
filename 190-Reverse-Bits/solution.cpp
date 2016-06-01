class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        // use a 32 loop.
        int r = 0;
        for(int i=0; i<32; i++)) // use while(n>0) for reversing numbers without leading zeros.
        {
            r <<= 1;
            r |= (n&1);
            n >= 1;
        }
        return r;
    }
};