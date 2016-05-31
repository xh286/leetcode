class Solution {
public:
    bool isUgly(int num) {
        // try to divide 2, 3, 5. If remainder nonzero for all of them, then not ugly.
        // corner cases: at least try 0, 1, 2, 3, 4. Also, negative numbers? Only positive numbers are ugly.
        if(num <= 0) return false;
        // if num is 1, return true.
        while(num > 1)
        {
            if( (num%2) == 0 )
                num /= 2;
            else if( (num%3) == 0 )
                num /= 3;
            else if( (num%5) == 0 )
                num /= 5;
            else
                return false;
        }
        assert(num == 1);
        return true;
    }
};