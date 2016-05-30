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
        vector<string> & base = a;
        vector<string> & derived = b;
        for(int d = 2; d <= n; d++) // d is the degree of the subproblem
        {
            base = (d&1)? &b : &a;    // if d odd, then copy from b to a. If d even, then copy from a to b.
            derived = (d&1)? &a : &b; // use a & b as ping-pong buffer. First time we derive b from a.
            // Always keep special solution at index zero
            derived.clear();
            derived.push_back(base[0]+"()"); // special solution gets extended
            derived.push_back("("+base[0]+")"); // special solution gets enclosed
            // All other solutions get derived in 3 ways, insert()before, append ()after, enclose
            for(int i=1; i< base.size(); i++)
            {
                derived.push_back("()"+base[i]);
                derived.push_back(base[i]+"()");
                derived.push_back("("+base[i]+")");
            }
        }
        return derived;
    }
};