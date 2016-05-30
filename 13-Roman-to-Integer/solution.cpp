class Solution {
private:
    int romanToInt_s(char a)
    {
        int i;
        switch(a)
        {
            case 'I': i = 1; break;
            case 'V': i = 5; break;
            case 'X': i = 10; break;
            case 'L': i = 50; break;
            case 'C': i = 100; break;
            case 'D': i = 500; break;
            case 'M': i = 1000; break;
            default:  i = 0;
        }
        return i;
    }
    
public:
    int romanToInt(string s) {
        int n = s.size();
        int output = 0;
        int this_val;
        int next_val = 0;
        for(int i=n-1; i>=0; i--)
        {
            this_val = romanToInt_s(s[i]);
            if(this_val<next_val)
                output -= this_val;
            else
                output += this_val;
            next_val = this_val;
        }
        return output;
    }
};