class Solution {
public:
    int numDecodings(string s) {
        /* DP solution. Define two arrays:
           a[i] for number of ways by s[i] and s[i] interpreted as single digit.
           b[i] for number of ways by s[i] and s[i] interpreted as second digit of a double digit.
           a[0] = 1, b[0] = 0.
           For i>=1, if s[i]==0, then a[i]=0, b[i]=a[i-1] if s[i-1]==1 or 2, otherwise 0.
           If s[i] 1~9, then a[i]=a[i-1]+b[i-1], b[i]=a[i-1] if s[i=1] ==1 or 2, and s[i] 0~6.
        */
        int n = s.size();
        if(n==0) return 0;
        if(s[0]=='0') return 0;
        vector<int> a(n,0);
        vector<int> b(n,0);
        a[0] = 1;
        for(int i=1; i<n; i++)
        {
            if(s[i]=='0')
            {
                a[i] = 0;
                if(s[i-1] == '1' || s[i-1] == '2')
                    b[i] = a[i-1];
                // otherwise b[i]=0
            }
            else
            {
                a[i] = a[i-1] + b[i-1];
                if(s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6'))
                    b[i] = a[i-1];
                // otherwise b[i]=0
            }
        }
        return a[n-1]+b[n-1];
    }
};