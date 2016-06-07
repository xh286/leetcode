class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // Same as permuting an array of numbers 1 to n. So assume input as [1, 2, ..., n]
        vector<int>& a = nums;
        vector<vector<int>> r;
        int n = a.size();
        // Think of generating permute(k+1) from permute(k): Each vector in permute(k) is added a new entry "k+1"
        // at one of the k+1 positions [1, ..., k+1], so size of r is multiplied by (k+1) and length of each row is increased by 1. A recursive solution would work, but not most efficient.
        // Iterative solution: total length of r is n! = n * (n-1) * ... * 1. Each row of r is same length.
        // Work in n iterations. Iteration 1 is trivial. Just insert a.
        // At iteration 2, there are two possible locations to "insert" 2 (k=1), and the last location is already used in previous rows. So we try 1 location "1".
        // At iteration k+1, there are k+1 possible locations and we duplicate from location k down to location 1.
        // For zero-based arrays, all the INDICES need to be reduced by 1.
        r.push_back(a);
        for(int k=1; k<n; k++) // (k+1) is iteration number. duplicate existing list k times.
        {
            int s = r.size(); // current size of r, we do duplication on each of the r rows, k times.
            for(int i=k-1; i>=0; i--) // move a[k] to a[i]. verify indices with k = 1, or iteration 2.
            {
                for(int j=0; j<s; j++) // do this for all s rows
                {
                    // Now do the copy and insert into r
                    r.push_back(vector<int>());
                    int p = r.size()-1; // p points to last vector, could change to a counter here
                    // "dup" from r[j] to r[p]. Move a[k] to a[i] and all entries [i+1...k-1] to the right, also copy [k+1...n]
                    for(int q=0; q<i; q++)
                        r[p].push_back(r[j][q]);
                    r[p].push_back(a[k]);
                    for(int q=i+1; q<=k; q++)
                        r[p].push_back(r[j][q-1]);
                    for(int q=k+1; q<n; q++)
                        r[p].push_back(r[j][q]);
                }
            }
        }
        return r;
    }
};