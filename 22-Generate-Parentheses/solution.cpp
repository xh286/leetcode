class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // Probably as long as at any point, the cumulative count of ')' does not exceed that of '(' then the sequence is valid.
        // So the '(' want to distribute to the left. Start with the right-most distribution, or ()()...().
        // Then swap some '(' with the ')' to the left of it. How many ways? 
        // Another problem is keep answers unique. Because we only move '(' to the left, there are no duplicates?
        vector<string> a;
        // insert first, base version
        string b(2n);
        for(int i=0; i<n; i++)
        {
            b[2*i] = '(';
            b[2*i+1] = ')';
        }
        a.push_back(b);
        char temp = '\0';
        if(n==1) return a; // guard against singular case, just in case...
        for(int r = 1; r < 2*n; r++) // index always pointing to first right parenthese ')' that can be swapped to the right.
        {
            for(int l = r+1; l < 2*n; l++)//index always pointing to first left parenthese '(' that can be swapped to the left.
            {
                assert( (b[r] == ')') && (b[l] == '(') );
                string c = b;
                c[r] = b[l];
                c[l] = b[r];
                a.push_back(c);
                // update l so that l points to next '('
                l++;
                while(b[l] != '(')
                    l++;
            }
        }
    }
};