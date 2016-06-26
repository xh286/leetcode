class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        if(s3.size() != (m+n)) return false;
        vector<vector<bool>> table(m+1, vector<bool>(n+1,false));
        // table[i][j] value indicates whether s3[0...i+j-1] is interleaving of s1[0...i-1] and s2[0...j-1].
        // Initialize
        table[0][0] = true;
        for(int j=1; j<=n; j++)
        {
            if(table[0][j-1] && s3[j-1] == s2[j-1])
                table[0][j] = true;
            else
                break;
        }
        for(int i=1; i<=m; i++)
        {
            if(table[i-1][0] && s3[i-1] == s1[i-1])
                table[i][0] = true;
            else
                break;
        }
        // table[i][j] == true if and only if any of the two is true:
        // table[i-1][j] == true, and s3[i+j-1] == s1[i-1].
        // table[i][j-1] == true, and s3[i+j-1] == s2[j-1].
        for(int i=1; i<=m; i++)
            for(int j=1; j<=n; j++)
            {
                if( (table[i-1][j] && s3[i+j-1] == s1[i-1]) ||
                    (table[i][j-1] && s3[i+j-1] == s2[j-1]) )
                    table[i][j] = true;
            }
        return table[m][n];
    }
};