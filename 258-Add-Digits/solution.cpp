class Solution {
public:
    int addDigits(int num) {
        int output = num;
        while(output >=10)
        {
            // add digits
            int a = output;
            int b = 0;
            while(a != 0)
            {
                b += a - (a/10)*10;
                a /= 10;
            }
            output = b;
        }
        return output;
    }
};