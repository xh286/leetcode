class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // Analyze the induction. Found: From n pairs to (n+1) pairs, the special solution ()()...() evolves by appending() at the end. All other solutions get 3 new versions: 1. Insert a () in front of it. 2. Append a () after it. 3. Enclose it with (). The special solution also gets evolved by enclosing it with ().
        // Problem is how to program this, as the structure of the output vector<string> gets changed many times, copies from self.
        // Use ping-pong and reference.
        string s("()"); // seed
        vector<string> a;
        vector<string> b;
        a.push_back(s);
        if(n == 1) return a; // get rid of singular case to avoid bugs
        // n >= 2
        for(int d = 2; d <= n; d++) // d is the degree of the subproblem
        {
            if(d&1 == 0) // d even iteration
            {
                // Always keep special solution at index zero
                b.clear();
                b.push_back(a[0]+"()"); // special solution gets extended
                b.push_back("("+a[0]+")"); // special solution gets enclosed
                // All other solutions get derived in 3 ways, insert()before, append ()after, enclose
                for(int i=1; i< a.size(); i++)
                {
                    b.push_back("()"+a[i]);
                    b.push_back(a[i]+"()");
                    b.push_back("("+a[i]+")");
                }
            }
            else // d odd iteration
            {
                // Always keep special solution at index zero
                a.clear();
                a.push_back(b[0]+"()"); // special solution gets extended
                a.push_back("("+b[0]+")"); // special solution gets enclosed
                // All other solutions get derived in 3 ways, insert()before, append ()after, enclose
                for(int i=1; i< b.size(); i++)
                {
                    a.push_back("()"+b[i]);
                    a.push_back(b[i]+"()");
                    a.push_back("("+b[i]+")");
                }
            }
        }
        return (n&1)?a:b;
    }
};