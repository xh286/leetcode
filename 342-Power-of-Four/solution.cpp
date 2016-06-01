class Solution {
public:
    bool isPowerOfFour(int num) {
        // first determine whether it's power to two. If yes, check the position of the 1 set bit.
        if(num <=0 ) return false;
        if( (num & (num -1)) != 0) return false; // power of 2 has single bits, subtract by 1, and &, should get zero.
        if( (num & (1<<1)) ||
            (num & (1<<3)) ||
            (num & (1<<5)) ||
            (num & (1<<7)) ||
            (num & (1<<9)) ||
            (num & (1<<11)) ||
            (num & (1<<13)) ||
            (num & (1<<15)) ||
            (num & (1<<17)) ||
            (num & (1<<19)) ||
            (num & (1<<21)) ||
            (num & (1<<23)) ||
            (num & (1<<25)) ||
            (num & (1<<27)) ||
            (num & (1<<29)) ||
            (num & (1<<31)) )
            return false;
        return true;
    }
};