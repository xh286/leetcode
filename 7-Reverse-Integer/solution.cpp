class Solution {
public:
    int reverse(int x) {
        // For trailing zeros, remove. For overflow, return INT_MIN and INT_MAX. But this problem requires 0...
        // For negative, get absolute first.
        int sign = 1;
        if(x < 0)
        {
            x = ~x + 1;// convert to absolute value
            sign = -1;
        }
        unsigned r = 0;
        while(x)
        {
            if(r > INT_MAX/10) return 0;
            r =  r*10;
            r += x%10;
            if((sign == 1 && r > (unsigned)INT_MAX) || (sign == -1) && (r > (unsigned)INT_MAX + 1)) return 0;
            x /= 10;
        }
        if(sign == -1)
        {
            r = (int)(~(r-1));
        }
        return (int)r;
    }
};