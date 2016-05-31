class Solution {
public:
    int hammingWeight(uint32_t n) {
        int r = 0;
        while(int i=0; i<32; i++)
        {
            if(n&1)
                r++;
            n >>= 1;
        }
        return r;
    }
};