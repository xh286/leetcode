class Solution {
public:
    int myAtoi(string str) {
        int n = str.size();
        int i = 0;
        unsigned r = 0;
        int sign = 1;
        bool overflow = false;
        while(i < n && isspace(str[i]))
            i++;
        if(i < n && (str[i] == '-' || str[i] == '+'))
        {
            sign = (str[i] == '-')? -1 : 1;
            i++;
        }
        while(i < n && isdigit(str[i]))
        {
            if(r > INT_MAX/10)
            {
                overflow = true;
                break;
            }
            r *= 10;
            r += str[i] - '0';
            if(r > INT_MAX) // r == INT_MIN treated as overflow case
            {
                overflow = true;
                break;
            }
            i++;
        }
        if(overflow)
        {
            return (sign == -1)? INT_MIN: INT_MAX;
        }
        return r * sign;
    }
};