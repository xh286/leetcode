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
    }
    
public:
    int romanToInt(string s) {
        int n = s.size();
        string a(n);
        vector<int> b(n);
        int output = 0;
        for(int i=0; i<n; i++)
        {
            b[i] = romanToInt_s(s[i]);
        }
        for(int i=0; i<n-1; i++)
        {
            if(b[i] < b[i+1])
                b[i] = -1 * b[i];
        }
        for(int i=0; i<n; i++)
        {
            output += b[i];
        }
        return output;
    }
};