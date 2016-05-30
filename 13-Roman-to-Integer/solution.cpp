class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        int output = 0;
        int this_val;
        int next_val = 0;
        for(int i=n-1; i>=0; i--)
        {
            switch(s[i])
            {
            case 'I': this_val = 1; break;
            case 'V': this_val = 5; break;
            case 'X': this_val = 10; break;
            case 'L': this_val = 50; break;
            case 'C': this_val = 100; break;
            case 'D': this_val = 500; break;
            case 'M': this_val = 1000; break;
            default:  this_val = 0;
            }
            if(this_val<next_val)
                output -= this_val;
            else
                output += this_val;
            next_val = this_val;
        }
        return output;
    }
};