class Solution {
private:
    void compactString(string &s) // remove all leading / trailing spaces, compact all consecutive spaces to single
    {
        int c = 0;
        int n = s.size();
        bool leading = true;
        bool pre_isspace = false;
        for(int i=0; i<n; i++)
        {
            if(isspace(s[i]))
            {
                if(leading || pre_isspace)
                    c++;
                else
                    s[i-c] = s[i];
                pre_isspace = true;
            }
            else
            {
                leading = false;
                pre_isspace = false;
                s[i-c] = s[i];
            }
        }
        // now string end is moved c places to the left
        // s[n-c] = s[n];
        // remove trailing spaces
        for(int i=n-c-1; i>=0; i--)
        {
            if(isspace(s[i]))
                c++;
            else
                break;
        }
        s[n-c] = s[n];
        s.resize(n-c);
    }
    void revString(char* p1, char* p2) // p1<=p2
    {
        while(p1<p2)
        {
            char t = *p1;
            *p1 = *p2;
            *p2 = t;
            p1++;
            p2--;
        }
    }
public:
    void reverseWords(string &s) {
        compactString(s);
        int n = s.size();
        if(n==0) return;
        char* p1 = &s[0];
        char* p2 = &s[n-1];
        revString(p1,p2);
        p1 = &s[0];
        p2 = p1;
        while(*p1)
        {
            while(*p1 && !isspace(*p1)) p1++;
            revString(p2, p1-1);
            while(isspace(*p1)) p1++;
            p2 = p1;
        }
    }
};