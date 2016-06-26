class Solution {
private:
    void removeLeadingspace(string &s)
    {
        int c = 0;
        char*p = &s[0];
        while(*p && isspace(*p1))
        {
            c++;
            p++;
        }
        if(c == 0) return;
        int n = s.size();
        for(int i=0; i<n-c; i++)
        {
            s[i] = s[i+c];
        }
        s[n-c] = '\0';
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
        int n = s.size();
        removeLeadingspace(s);
        char* p1 = &s[0];
        char* p2 = &s[n-1];
        revString(p1,p2);
        removeLeadingspace(s);
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