class Solution {
public:
    int uniquePaths(int m, int n) {
        // Defer optimizations!
        if(m<1 || n<1) return 0;
        vector<int> v(n,1);
        for(int j=1; j<m; j++)
        {
            for(i=1; i<n; i++)
            {
                v[i] += v[i-1];
            }
        }
        return v[n-1];
    }
};