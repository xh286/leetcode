class Solution {
    
public:
    string longestPalindrome(string s) {
        // Center of palindrome could be s[i], 0...n-1 if odd length.
        // Center could be in betweeen s[i] and s[i+1], 0...n-2, if even length.
        // Check both cases, when updating max_len, also update start & end.
        int n = s.size();
        if(n==0) return s;
        int max_len = 1;
        int start = 0;
        int end = 0;
        // check odd length case first, skip length = 1 case.
        for(int i=1; i<= n-2; i++)
        {
            int j = 1;
            while(i-j>=0 && i+j<n)
            {
                if(s[i-j] == s[i+j])
                    j++;
            }
            j--;
            if(j*2+1 > max_len)
            {
                max_len = j*2+1;
                start = i-j;
                end = i+j;
            }
        }
        // check even length case.
        for(int i=0; i<=n-2; i++)
        {
            if(s[i] == s[i+1])
            {
                int j = 1;
                while(i-j>=0 && i+1+j<n)
                {
                    if(s[i-j] == s[i+1+j])
                        j++;
                }
                j--;
                if(j*2+2 > max_len)
                {
                    max_len = j*2+2;
                    start = i-j;
                    end = i+1+j;
                }
            }
        }
        return string(&s[start], &s[end+1]);
    }
};