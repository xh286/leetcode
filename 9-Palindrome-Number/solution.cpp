class Solution {
public:
    bool isPalindrome(int x) {
        int z = x; // copy original value of x
        // does not handle negatives
        if(x<0) return false; // or x = 0-x;
        int y = 0;
        while(x > 0)
        {
            y *= 10;
            y += (x%10);
            x /= 10;
        }
        return (z==y);
    }
};