class Solution {
public:
    int titleToNumber(string s) {
        // A base 26 number. A-Z map to 1-26.
        int n = s.size(); // length n array, indices [0 - (n-1)] valid.
        int i;
        int output = 0;
        for(i = 0; i < n; ++i)
        {
            if( (s[i] < 'A') || (s[i] > 'Z') )
                return 0; // return invalid value when input invalid
            output *= 26;
            output += s[i] - 'A' + 1;
        }
        return output;
    }
};