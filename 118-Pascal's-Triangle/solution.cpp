class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int n = numRows;
        if(n <=0) return vector<vector<int>>(); // empty result
        vector<vector<int>> r(n,vector<int>(1,1)); // insert 1 in all rows
        for(int i=1; i<n; i++)
        {
            for(int j=1; j<i; j++) // row i has (i+1) entries, including 2 1s.
                r[i].push_back(r[i-1][j-1]+r[i-1][j]);
            r[i].push_back(1);
        }
        return r;
    }
};