class Solution {
private:
    int trinary_xor(int a, int b)
    {
        // Add two numbers in base 3, and without carry bits at any level.
        // Note that adding two numbers in base 2 (binary) can be achieved by ^(bit-wise xor) and &(bit-wise and) recursively until the carry flag mask becomes zero.
        int c = 0;
        int i = 1;
        while(a || b) // a and b will keep reducing, stop when both reach zero.
        {
            c += (((a%3) + (b%3))%3) * i; // could be optimized, like xor lowest bit in binary
            a /= 3; // truncate a%3, then divide by 3, like shift right in binary
            b /= 3;
            i *= 3;
        }
        // Question: how do we handle negative numbers a & b?
        return c;
    }
    int trinary_mapback(int a)
    {
        int b = 0;
        int i = 1;
        while(a)
        {
            if(a%3 == 1)
                b += 2*i;
            else if(a%3 == 2)
                b += 1*i;
            a /= 3;
            i *= 3;
        }
        return b;
    }
public:
    int singleNumber(vector<int>& nums) {
        // Extension to the twice except for one problem. Extend xor for binary representation to trinary.
        // xor: (0, 0) -> 0, (1, 1) -> 0, (0, 1) -> 1, (1, 0) -> 1. The essence is to keep individual bits separate, add without carry.
        // Trinary Add without carry: (0, 0, 0) -> 0, (1, 1, 1) -> 0, (2, 2, 2) -> 0. How many times do the single one appear? If once/four/seven times then easier. If twice/five times, then (1, 1) -> 2, (2, 2) -> 1, there is a way to get back.
        // What if 5 times? assume once, then no change, twice, then (0,0)->0, (1,1)->2, (2,2)->4, (3,3)->1, (4,4)->3. Three times, then (0)->0, (1)->3, (2)->1, (3)->4, (4)->2. Always unique mapping. Four times, 0, 4, 3, 2, 1.
        // How to add two numbers in base 3 without carry?
        int n = nums.size();
        int result = 0;
        for(int i=0; i<n; i++)
        {
            result = trinary_xor(result, nums[i]);
        }
        // try once/four/seven/... times
        int occurence = 0;
        for(int i=0; i<n; i++)
        {
            if(nums[i] == result)
                occurence++;
        }
        if(occurence > 0 && occurence != 3)
            return result;
        // try twice/five/eight/... times
        result = trinary_mapback(result);
        occurence = 0;
        for(int i=0; i<n; i++)
        {
            if(nums[i] == result)
                occurence++;
        }
        if(occurence > 0 && occurence != 3)
            return result;
    }
};